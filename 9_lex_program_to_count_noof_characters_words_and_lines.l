%{
#include<stdio.h>
#include<stdlib.h>
int cno=0, wno=0,lno=1;
%}
characters [a-zA-Z]
digit [0-9]
word ({characters}|{digit})+
line \n
%%
{line} { cno++; lno++;}
{word} {wno++; cno+=strlen(yytext);}
. {cno++;}
%%
int main(void)
{
yylex();
printf("\nnumbers of characters:%d",cno);
printf("\nnumbers of words:%d",wno);
printf("\nnumbers of lines:%d",lno);
return 0;
}
int yywrap()
{
}
