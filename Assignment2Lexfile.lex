%{
#include <stdlib.h>
#include "y.tab.h"
%}
%%
[a-z] {
            yylval = yytext[0] - 'a';
            return(ID);
}
[0-9]+ {
yylval = atoi(yytext);
return NUM;
}
[ \t] ; /* skip whitespace */
.|\n {return yytext[0];}

%%
int yywrap(void) {
return 1;
}