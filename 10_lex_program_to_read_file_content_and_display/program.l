%{
#include <stdio.h>
%}

%%
[\n \t ' ']  {};
%%

int main() {
    yyin = fopen("input", "r");
    yylex();
}

int yywrap() {
    return 1;
}
