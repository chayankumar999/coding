%{
    #include<stdio.h>
    #include<string.h>
    void yyerror(char *);
%}
%token TRUE FALSE AND OR NOT
%left AND OR
%right NOT

%%
line:
    line expr '\n' { printf("The Expression is = %s\n", $2?"TRUE":"FALSE");}
    | line '\n'
    |
    |error '\n' {yyerror("Reenter the prev line"); yyerrok;}
    ;
expr:
    TRUE { $$ = $1; }
    |
    FALSE { $$ = $1; }
    | expr AND p { $$ = $1 & $3; }   
    | expr OR expr { $$ = $1 | $3; }
    | '(' expr ')' { $$ = $2; }
    | NOT expr  { $$ = !($2); }
    ;
%%
void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}
int main()
{
    yyparse();
    return 0;
}

