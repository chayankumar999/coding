%{
	#include<bits/stdc++.h>
	using namespace std;
	int CL,SL;
%}

delim[ \t\n]
ws{delim}+
Capitalletter[A-Z]
SmallLetter[a-z]
special[#|$|~|?|'|"]

%%

{ws} ;
{Capitalletter} {CL++;}
{SmallLetter} {SL++;}
{special} { cout<<"Find a special character: "<<yytext<<endl;}

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
		cout<<"Count of Capital Letter = "<<CL<<endl;
		cout<<"Count of Small Letter   = "<<SL<<endl;
	}
	getchar();
	return 0;
}