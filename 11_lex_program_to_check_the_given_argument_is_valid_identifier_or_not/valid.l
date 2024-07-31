%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]* { return LET; }
[0-9] { return DIG; }
. { return yytext[0]; }
\n { return 0; }
%%

int yywrap() {
    return 1;
}
