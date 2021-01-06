%{
#include <stdio.h>
#define YYSTYPE int
int yyprase(void);
int yylex();
void yyerror(char* s);
%}

%token NUMBER PLUS MINUS TIMES DIVIDE LP RP IF THEN ELSE END TERMINAL

%%
command:exp TERMINAL{printf("%d\n",$1);$$ = $1;}
|command exp TERMINAL{printf("%d\n",$2);$$ = $2;}
exp:IF exp THEN exp ELSE exp END {$$ = $2 !=0 ? $4 : $6;}
|exp PLUS term {$$ = $1 + $3;}
|exp MINUS term {$$ = $1 - $3;}
|term {$$ = $1;}
;
term: term TIMES factor {$$ = $1 * $3;}
|term DIVIDE factor {$$ = $1 / $3;}
|factor {$$ = $1;}
;
factor: NUMBER {$$ = $1;}
|LP exp RP {$$ = $2;}
;
%%
int main()
{
    return yyparse();
}
void yyerror(char* s)
{
    fprintf(stderr,"%s",s);
}
int yywrap()
{
    return 1; 
} 