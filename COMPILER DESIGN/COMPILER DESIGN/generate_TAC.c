#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char input[MAX];
int tempVarCounter = 0;

typedef struct {
    char result[10];
    char arg1[10];
    char op;
    char arg2[10];
} TAC;

TAC tac[MAX];
int tacIndex = 0;

void generateTAC(char *result, char *arg1, char op, char *arg2) {
    strcpy(tac[tacIndex].result, result);
    strcpy(tac[tacIndex].arg1, arg1);
    tac[tacIndex].op = op;
    strcpy(tac[tacIndex].arg2, arg2);
    tacIndex++;
}

void printTAC() {
    printf("\nThree Address Code:\n");
    for (int i = 0; i < tacIndex; i++) {
        printf("%s = %s %c %s\n", tac[i].result, tac[i].arg1, tac[i].op, tac[i].arg2);
    }
}

void parseExpression(char *expr) {
    char tempVar[10], left[10], right[10], op;
    int len = strlen(expr);
    int i, j;

    for (i = 0; i < len; i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            op = expr[i];
            strncpy(left, expr, i);
            left[i] = '\0';
            strncpy(right, expr + i + 1, len - i - 1);
            right[len - i - 1] = '\0';

            sprintf(tempVar, "t%d", tempVarCounter++);
            generateTAC(tempVar, left, op, right);
            strcpy(expr, tempVar);
            break;
        }
    }
}

void processInput(char *input) {
    char expr[MAX];
    strcpy(expr, input);

    while (strchr(expr, '+') || strchr(expr, '-') || strchr(expr, '*') || strchr(expr, '/')) {
        parseExpression(expr);
    }
}

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);

    processInput(input);
    printTAC();

    return 0;
}
