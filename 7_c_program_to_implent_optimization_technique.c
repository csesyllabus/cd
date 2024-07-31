#include <stdio.h>
#include <string.h>

struct op {
    char l;
    char r[20];
} op[10], pr[10];

int main() {  // Changed 'void main()' to 'int main()' for standard compliance
    int a, i, j, n, z = 0, m, q;
    char *p, *l;
    char temp, t;
    char *tem;

    printf("Enter the number of instructions: ");
    scanf("%d", &n);
    printf("Enter the instructions (LEFT RIGHT format): \n");
    for (i = 0; i < n; i++) {
        printf("Instruction %d - LEFT: ", i + 1);
        scanf(" %c", &op[i].l);
        printf("Instruction %d - RIGHT: ", i + 1);
        scanf("%s", op[i].r);
    }

    printf("Intermediate code:\n");
    for (i = 0; i < n; i++) {
        printf("%c = %s\n", op[i].l, op[i].r);
    }

    for (i = 0; i < n - 1; i++) {
        temp = op[i].l;
        for (j = 0; j < n; j++) {
            p = strchr(op[j].r, temp);
            if (p) {
                pr[z].l = op[i].l;
                strcpy(pr[z].r, op[j].r);
                z++;
            }
        }
    }
    pr[z].l = op[n - 1].l;
    strcpy(pr[z].r, op[n - 1].r);
    z++;

    printf("\nAfter Dead Code Elimination:\n");
    for (i = 0; i < z; i++) {
        printf("%c = %s\n", pr[i].l, pr[i].r);
    }

    for (m = 0; m < z; m++) {
        tem = pr[m].r;
        for (j = m + 1; j < z; j++) {
            p = strstr(tem, pr[j].r);
            if (p) {
                t = pr[j].l;
                pr[j].l = pr[m].l;
                for (i = 0; i < z; i++) {
                    l = strchr(pr[i].r, t);
                    if (l) {
                        a = l - pr[i].r;
                        pr[i].r[a] = pr[m].l;
                    }
                }
            }
        }
    }

    printf("After Common Subexpression Elimination:\n");
    for (i = 0; i < z; i++) {
        printf("%c = %s\n", pr[i].l, pr[i].r);
    }

    for (i = 0; i < z; i++) {
        for (j = i + 1; j < z; j++) {
            if (pr[i].l == pr[j].l && strcmp(pr[i].r, pr[j].r) == 0) {
                pr[j].l = '\0';  // Mark duplicate instructions
            }
        }
    }

    printf("\nOptimized code:\n");
    for (i = 0; i < z; i++) {
        if (pr[i].l != '\0') {
            printf("%c = %s\n", pr[i].l, pr[i].r);
        }
    }

    return 0;
}
