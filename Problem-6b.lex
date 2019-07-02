%{
	#include<bits/stdc++.h>
	using namespace std;
%}

newline[\n]
backslash[/]
star[*]
SC {backslash}({backslash})+
MCB {backslash}|{star}
MCE {star}|{backslash}

%%
/ { cout<<yytext<<endl; }
{newline}
{
	
}

{SC} 
{
	cout<<yytext<<endl;
}
{MCE}
{
	
}
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
	}
	getchar();
	return 0;
} 