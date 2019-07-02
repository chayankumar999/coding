%{
	#include<bits/stdc++.h>
	using namespace std;
%}
delim[ \t\n]
ws{delim}+
letter[A-Za-z]
digit[0-9]
id {letter}({letter}|{digit})*
inumber {digit}+
fnumber {digit}+(\.{digit}+)?


%%

{ws} ;
int { cout<<"Find a keyword : "<<yytext<<endl; }
float { cout<<"Find a keyword : "<<yytext<<endl; }
if { cout<<"Find a keyword : "<<yytext<<endl; }
then { cout<<"Find a keyword : "<<yytext<<endl; }
else { cout<<"Find a keyword : "<<yytext<<endl; }
for { cout<<"Find a keyword : "<<yytext<<endl; }
printf { cout<<"Find a keyword : "<<yytext<<endl; }
switch { cout<<"Find a keyword : "<<yytext<<endl; }
case { cout<<"Find a keyword : "<<yytext<<endl; }
return { cout<<"Find a keyword : "<<yytext<<endl; }
{inumber} { cout<<"Find a integer number : "<<yytext<<endl; }
{fnumber} { cout<<"Find a float number : "<<yytext<<endl; }
. ;

%%

int yywrap()
{
return 1;
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