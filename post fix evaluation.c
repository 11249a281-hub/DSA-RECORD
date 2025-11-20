#include <stdio.h>
#include <ctype.h>   // for isdigit()

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    char *e;
    int n1, n2, num;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    e = exp;

    while (*e != '\0') {

        // If operand → push to stack
        if (isdigit(*e)) {
            num = *e - '0';     // convert char to int
            push(num);
        }
        // If operator → pop two, operate, push result
        else {
            n2 = pop();
            n1 = pop();

            switch (*e) {
                case '+': push(n1 + n2); break;
                case '-': push(n1 - n2); break;
                case '*': push(n1 * n2); break;
                case '/': push(n1 / n2); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < n2; i++)
                        result *= n1;
                    push(result);
                    break;
                }
            }
        }
        e++;
    }

    printf("Result = %d\n", pop());
    return 0;
}
