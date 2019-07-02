%{
    #include<stdio.h>
    void yyerror(char *);
%}
%token ID NUM
%left '+' '-'
%left '*' '/'
%right '%'
%right UnaryMinus

%%
line:
    line ID '=' expr '\n' { printf("%c = %d\n", $2, $4); };
    |
    line expr '\n' { printf("%d\n", $2); }
    | line '\n'
    |
    |error '\n' {yyerror("Invalid Expression"); yyerrok;}
    ;
expr:
    NUM { $$ = $1; }
    | expr '+' expr { $$ = $1 + $3; }   
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr
                    {
                        if($3==0)
                        {  yyerror("divide 0 error!!"); getch(); YYABORT; }
                        else
                            $$ = $1 / $3;
                    }
    | '(' expr ')' { $$ = $2; }
    | expr '%' expr { $$ = $1 % $3; }
    |'-' expr %prec UnaryMinus {$$ = - $2;}
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

