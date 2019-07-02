%{
#include <stdlib.h>
#include "y.tab.h"
%}
%%
[0-9]+ {
yylval = atoi(yytext);
return INTEGER;
}
[a-z] {
            yylval = yytext[0];
            return(LETTER);
 }
[ \t] ; /* skip whitespace */
.|\n {return yytext[0];}

%%
int yywrap(void) {
return 1;
}    