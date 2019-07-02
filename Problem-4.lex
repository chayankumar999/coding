%{
	#include<bits/stdc++.h>
	using namespace std;
%}


letter[A-F]
digit[0-9]
Decimal {digit}+
Hexadecimal {letter}*{digit}*{letter}*{digit}*

%%

{Decimal} { cout<<yytext<<" is a Decimal number"<<endl; }
{Hexadecimal} { cout<<yytext<<" is a Hexadecimal number"<<endl;}

%%

int yywrap()
{
return 1;
}
int main()
{
	while(yylex())
	{
		
	}
	return 0;
}