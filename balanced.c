#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) { stack[++top] = ch; }
char pop() { return stack[top--]; }

int isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else {
            if (top == -1) return 0;
            char ch = pop();
            if ((exp[i] == ')' && ch != '(') ||
                (exp[i] == '}' && ch != '{') ||
                (exp[i] == ']' && ch != '['))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);
    printf(isBalanced(exp) ? "Balanced" : "Not Balanced");
    return 0;
}
