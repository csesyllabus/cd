%{
%}

identifier [a-z A-Z][a-z A-Z 0-9]*

%%

#.* { printf("\n%s is a Preprocessor Directive", yytext); }
int|float|main|if|else|printf|scanf|for|char|getch|while {
    printf("\n%s is a Keyword", yytext);
}

{identifier}\( {printf("\nFunction:\t%s", yytext); }
\{ {printf("\nBlock Begins"); }
\} {printf("\nBlock Ends"); }
{identifier} {printf("\n%s is an Identifier", yytext); }

.|\n

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("\nCould not open the file: %s", argv[1]);
            exit(0);
        }
        yyin = file;
    }
    yylex();
    printf("\n\n");
    return 0;
}

int yywrap() {
    return 0;
}
