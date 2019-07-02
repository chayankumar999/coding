%{
	#include<bits/stdc++.h>
	using namespace std;

	set<string>words;
	set<string>::iterator it;
	string s="";

	
%}
delim[ \t\n]
ws{delim}+
letter[A-Za-z]
word {letter}+
%%

. ;
{ws} ;
{word} {s=yytext; if(s.size()==3 && s[0]=='A') words.insert(s);}

%%

int yywrap()
{
	return 1 ;
}
int main()
{
	FILE *myfile = fopen("C:\\Users\\chayan kumar roy\\Desktop\\example.txt","r");

	if(!myfile)
	{
		cout<<"can't open a file"<<endl;
	}
	else
	{
		yyin = myfile;
		yylex();
		fclose(myfile);
		if(!words.size()) cout<<"there is no word of length three or start with 'A' "<<endl;
		else
		{
			cout<<"list of all words of length three which are starting with 'A' are : "<<endl;
			for(it=words.begin();it!=words.end();it++) cout<<*it<<endl;
		}
	}

	getchar();
	return 0;
} 