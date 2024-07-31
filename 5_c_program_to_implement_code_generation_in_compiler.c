#include <stdio.h>
#include <string.h>
int main()
{
    char s[10][10];
    int i, n;
    printf("Enter the number of address  statements : ");
    scanf("%d", &n);
    printf("Enter the address statements : \n");
    for (i = 0; i < n; i++)
        scanf("%s", s[i]);

    for (i = 0; i < n; i++)
    {
        if (strlen(s[i]) < 3 || strlen(s[i]) > 5)
        {
            printf("Invalid statement\n");
            return 0;
        }
        printf("\nThe code generated is : \n");
        if (strlen(s[i]) == 5)
        {
            printf("LOAD %c R%d\n", s[i][4], i);
            switch (s[i][3])
            {
            case '+':
                printf("ADD");
                break;
            case '-':
                printf("SUB");
                break;
            case '*':
                printf("MUL");
                break;
            case '/':
                printf("DIV");
                break;
            case '%':
                printf("MOD");
                break;
            }
            printf(" %c R%d\n", s[i][2], i);
            printf("STORE R%d, %c\n", i, s[i][0]);
        }
        if (strlen(s[i]) == 4)
        {
            printf("LOAD %c R%d\n", s[i][3], i);
            printf("NEG R%d\n", i);
            printf("STORE R%d, %c\n", i, s[i][0]);
        }
        if (strlen(s[i]) == 3)
        {
            printf("LOAD %c R%d\n", s[i][2], i);
            printf("STORE R%d, %c\n", i, s[i][0]);
        }
        printf("\n");
    }
    return 0;
}