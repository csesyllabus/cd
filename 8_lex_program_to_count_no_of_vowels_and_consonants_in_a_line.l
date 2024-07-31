%{
#include <stdio.h>

int vowels = 0;
int cons = 0;
%}

%%
[aeiouAEIOU]  { vowels++; }
[a-zA-Z]      { cons++; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the string (end with ctrl+D):\n");
    yylex();
    printf("Number of vowels = %d\nNumber of consonants = %d\n", vowels, cons);
    return 0;
}
