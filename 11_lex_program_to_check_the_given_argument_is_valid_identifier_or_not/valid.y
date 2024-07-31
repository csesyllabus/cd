%{
#include <stdio.h>
#include <stdlib.h>
%}

%token LET DIG

%%
variable: var
;

var: LET var
   | LET
   | LET DIG
   ;

%%

int main() {
    printf("Enter the variable: ");
    yyparse();
    printf("Valid variable\n");
    return 0;
}

int yyerror() {
    fprintf("Invalid variable.\n");
    return 0;
}
