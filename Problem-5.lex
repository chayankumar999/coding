
%{
	#include<bits/stdc++.h>
        using namespace std;
	int NOW,NOC,NOL,f;
%}
space[ ]
newline[\n]
letter[A-Za-z]
digit[0-9]
other[;|:|,|\.|?|'|"]
%%

{letter} { NOC++; f=1; }
{newline} { NOL++; f=0; }
{digit} { NOC++; }
{other} { NOC++; }
{space} { if(f) NOW++; NOC++; f=0; }

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
		printf("can't open a file\n");
	}
	else
	{
		yyin = myfile;
		yylex();
		fclose(myfile);
		cout<<"Total number of Character  = "<<NOC<<endl;
		cout<<"Total number of Word       = "<<NOW<<endl;
		cout<<"Total number of Line       = "<<NOL<<endl;
	}
	getchar();
	return 0;
}