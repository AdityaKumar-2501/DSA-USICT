/*  ---------------PROBLEM STATEMENT ---------------
   Implement the conversion of infix notation to postfix notation
*/

#include <stdio.h>
#include <string.h>
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

void infixToPostfix(char* infix){
    char postfix[SIZE] = "";
    char stack[SIZE] = "";
    int top = -1;
    stack[++top] = '(';

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
                printf("\n***INVALID***\n");
                return;
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

    printf("Postfix Expression : %s\n", postfix);

}


int main(){
    char infix[SIZE];
    printf("Enter Infix Expression : ");
    fgets(infix, SIZE, stdin); // read string

    // Remove the newline character added by fgets
    infix[strcspn(infix, "\n")] = '\0';

    // Adding sentinal to infix expression
    int length = strlen(infix);
    if (length < SIZE - 1) {
        infix[length] = ')';
        infix[length + 1] = '\0'; // Ensure the string is null-terminated
    }else {
        printf("Infix expression is too long to append ')'\n");
    }
    infixToPostfix(infix);
    return 0;
}