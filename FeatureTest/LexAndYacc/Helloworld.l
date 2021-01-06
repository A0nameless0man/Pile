%{
#include<stdio.h>
#include"HelloWorld.tab.h"
// int yylval;
// zero 0
// binbit {zero}|1
// octbit {binbit}|[2-7]
// decbit {decbit}|[8-9]
// hexbit {decbit}|[a-fA-F]
%}
zero 0
binbit [0-1]
octbit [0-7]
decbit [0-9]
hexbit [0-9a-fA-F]

binpfx 0[bB]
octpfx 0
hexpfx 0[xX]

binint {binpfx}{binbit}+
octint {octpfx}{octbit}+
decint ([1-9]{decbit}*)|{zero}
hexint {hexpfx}{hexbit}+


plus "+"
minus "-"
times "*"
divide "/"
lp "("
rp ")"
ws [ \n\t]

if if
else else
then then
end end
terminal ;
%%
{binint} {sscanf(yytext, "%d", &yylval);/*printf("bin:%d(%s)\n", yylval, yytext);*/ return NUMBER;}
{octint} {sscanf(yytext, "%d", &yylval);/*printf("oct:%d(%s)\n", yylval, yytext);*/ return NUMBER;}
{decint} {sscanf(yytext, "%d", &yylval);/*printf("dec:%d(%s)\n", yylval, yytext);*/ return NUMBER;}
{hexint} {sscanf(yytext, "%d", &yylval);/*printf("hex:%d(%s)\n", yylval, yytext);*/ return NUMBER;}
{plus} {return PLUS;}
{minus} {return MINUS;}
{times} {return TIMES;}
{divide} {return DIVIDE;}
{lp} {return LP;}
{rp} {return RP;}
{if} {return IF;}
{then} {return THEN;}
{else} {return ELSE;}
{end} {return END;}
{terminal} {return TERMINAL;}
{ws} {;}
%%