#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return 'x';
}

void printstat() {
    printf("\n\t\t\t$");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
}

int main() {
    char s1[20];
    printf("\n\n\t\tLR parsing");
    printf("\n\t\tEnter the expression: ");
    scanf("%s", s1);

    int i = 0;
    int length = strlen(s1);

    printf("\n\t\t$");
    for (i = 0; i < length; i++) {
        if (s1[i] == 'i' && s1[i + 1] == 'd') {
            s1[i] = ' ';
            s1[i + 1] = 'E';
            printstat();
            printf("id");
            push('E');
            printstat();
            i++;
        } else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/' || s1[i] == 'd') {
            push(s1[i]);
            printstat();
        }
    }

    printstat();
    while (top != -1) {
        char ch1 = pop();
        if (ch1 == 'x') {
            printf("\n\t\t\t$");
            break;
        }
        if (ch1 == '+' || ch1 == '/' || ch1 == '*' || ch1 == '-') {
            char ch3 = pop();
            if (ch3 != 'E') {
                printf(" error");
            } else {
                push('E');
                printstat();
            }
        }
    }

    return 0;
}
