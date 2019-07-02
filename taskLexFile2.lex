%{
#include <stdlib.h>
#include "y.tab.h"
%}
%%
"true" {  yylval=1; return (TRUE); }
"false" { yylval =0; return(FALSE); }
"and" { return AND; }
"or" {return OR; }
"not" {return NOT; }
[ \t] ; /* skip whitespace */
.|\n {return yytext[0];}

%%
int yywrap(void) {
return 1;
}