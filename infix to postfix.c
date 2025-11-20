#include <stdio.h>
#include <ctype.h>   // for isdigit(), isalpha()
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;  // highest precedence
    return 0;
}

int main() {
    char exp[100];
    char *e, x;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    e = exp;

    printf("Postfix expression: ");

    while (*e != '\0') {
        // If operand, print directly
        if (isalnum(*e)) {
            printf("%c", *e);
        }
        // If opening bracket, push it
        else if (*e == '(') {
            push(*e);
        }
        // If closing bracket, pop until '('
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        // Operator encountered
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    // Pop remaining operators
    while (top != -1)
        printf("%c", pop());

    printf("\n");
    return 0;
}
