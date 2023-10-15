#include <string.h>
#include <stdlib.h>
#define SIZE 100

int check_priority(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    return -1;
}

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return 1;
    }
    return 0;
}

char* infixToPostfix(char* infix){
    char postfix[SIZE] = "";
    char stack[SIZE] = "";
    int top = -1;

    for(int i = 0 ; infix[i] != '\0' ; i++){
        if(infix[i]==' ')
            continue;
        else if(infix[i] == '('){
            top++;       
            stack[top] = infix[i];
        }
        // Add any alphabets or no. to postfix
        else if(isOperator(infix[i]) == 0 && infix[i]!='(' && infix[i]!=')'){
            int len = strlen(postfix);
            postfix[len] = infix[i];
            postfix[len + 1] = '\0';
        }
        // check for closing paranthesis
        else if(infix[i] == ')'){              
            while (top >= 0 && stack[top] != '(') {
                int len = strlen(postfix);
                postfix[len] = stack[top];
                postfix[len + 1] = '\0';
                top--;
            }
            if (top >= 0 && stack[top] != '(') {
                return "Error";
            } else {
                top--;
            }
        }
        // check for operator
        else if(isOperator(infix[i])){
            // poping operator from stack till precedences of operator in stack is >= precedence of operator in infix.
             while (top >= 0 && check_priority(stack[top]) >= check_priority(infix[i])) {
                int len = strlen(postfix);
                postfix[len] = stack[top];
                postfix[len + 1] = '\0';
                top--;
            }
            stack[++top] = infix[i];
        }
        
        
    }
    // Empty the stack
    while (top >= 0) {
        int len = strlen(postfix);
        postfix[len] = stack[top];
        postfix[len + 1] = '\0';
        top--;
    }
    // Allocate memory for the result and copy the postfix expression
    char* result = (char*)malloc(strlen(postfix) + 1);
    if (result != NULL) {
        strcpy(result, postfix);
    }

    return result;
}
