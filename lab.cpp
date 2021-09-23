#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

string keyWord[32]=
{
		"auto","break","case","char","const","continue","default","double",
		"do","else","enum","extern","float","for","goto","if","int","long",
		"register","return","short","signed","sizeof","static","struct",
		"switch","typedef","union","unsigned","void","volatile","while"
};

vector<int> CaseNum;
int switchNum=0;
int caseNum=0;
int totalNum=0;
int stack[1000]={0};
int ifelseNum=0;
int ifelseifElseNum=0;
int first=-1;


int text1( string x, string y )
// define a function to compare with the keyword that returns 1, not 0
{
	int text2( char str );
	int position = x.find( y , 0 );
	int len = y.length();	
	if( position != string::npos )
	{
		if( position == 0 ) 
		{
			if(text2( x[position+len] ) == 0 )
			{
				return 1;
			}
			else 
			  	return 0;
		}
		else
		{
			if(text2( x[position+len] ) == 0 && text2( x[position-1] ) ==0 )
			{
				return 1;
			}
			else
				return 0;
		}
	}
	return 0;
}



int text2( char str )
//Determine letters or numbers.It returns "1", not "0".
{
	if( ( str<='z' && str >= 'a' ) || ( str <= 'Z' && str >= 'A' ) )
		return 1;
	else
		return 0;
}



void level_12(string str)
//Core character alignment, and count the number of switch-case
{
		for(int i = 0; i < 32; i++ )
		{
			if(text1( str , keyWord[i] ) == 1)
			{
				if( text1( str , "switch" ) )
				{
					CaseNum.push_back( caseNum );
					switchNum++;
					caseNum = 0;
				}
				if( text1( str , "case" ))
				{
					caseNum++;
				}
				totalNum++;
				break;
			}
		}
}


void level_34( string str ){
//If_else count and if_elseif_else nested count
	if( text1( str , "else if" ) )
	{
		first++;
		stack[first] = 2;
	}	
	else
	{
		if( text1( str , "else" ) )
		{
			 if( stack[first] == 1 )
			 {
			 	ifelseNum++;
			 	first--;
			 }
			 else
			 {
			 	if( stack[first] == 2 )
			 	{
			 		ifelseifElseNum++;
			 		first--;
				 }
			 }
		}
		else
		{
			if( text1( str ,"if" ) )
			{
				first++;
				stack[first] = 1;
			}
		}
	}
}



int main()
{
	int level;
	string Myfile,temp;
	cout << "The file path£º" << endl;
	//Input the file path.
	cin >> Myfile;
	cout << "level£º" << endl;
	cout << "1 stands for Total" << endl;
	cout << "2 stands for Switch-case" << endl;
	cout << "3 stands for If_else" << endl;
	cout << "4 stands for IF_elseif_Else" << endl;
	cin >> level;
	ifstream myfile( Myfile.c_str() );
	int text1( string x,string y );
	int text2( char str);
	void level_12( string str );
	//Call level -12
	void level_34( string str );
	//Call level -34 
	while ( getline( myfile ,temp ))
	// Read line by line
	{
		istringstream is ( temp );
		string s;
		if( level >= 3)
		{
			level_34( temp );
		}
		while( is >> s ) 
		{
			level_12( s );
		}
	}
	if( level >= 1 ) 
	{
		cout << "Total num:" << totalNum << endl;
	}
	if( level >= 2 )
	{
		cout << "Switch num:" << switchNum << endl;
		if( !CaseNum.empty() )
		{
			CaseNum.push_back(caseNum);
		}
		else
		{
			CaseNum.push_back(0);
		}
		cout << "Case num :";
		for ( int i = 1; i <= switchNum; i++)
		{
			cout<< CaseNum[i] << " ";
		}
		cout << endl;
	}
	if(level >=3 )
	{
		cout << "If-else num:" << ifelseNum << endl;
	}
	if( level >=4 )
	{
		cout << "If-elseif-else num:" <<ifelseifElseNum;
	}
}







