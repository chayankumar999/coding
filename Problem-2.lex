%{
	#include<bits/stdc++.h>
	using namespace std;
%}

delim[ \t\n]
ws{delim}+
or[|]
and[&]
relop >=|<=|==|<|>
arithOp [+|\-|*|/]
logical !|{or}+|{and}+|^

%%
{ws} ;
{relop} { cout<<"Find a Relational operator : "<<yytext<<endl; }
{arithOp} { cout<<"Find an Arithmatic operator : "<<yytext<<endl; }
{logical} { cout<<"Find a Logical operator : "<<yytext<<endl; }
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