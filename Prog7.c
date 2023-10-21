/*  ---------------PROBLEM STATEMENT ---------------
   Implement evaluation of postfix notation using stacks.
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
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

int isEmptyExpression(char *infix) {
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] != ' ' && infix[i] != '\n') {
            return 0; // The expression is not empty
        }
    }
    return 1; // The expression is empty
}

int check_paranthesis(char *infix){
    char ps[SIZE];
    int top = -1;
    for(int i = 0 ; infix[i] != '\0' ; i++){
        if(infix[i] == '('){
            ps[++top] = infix[i];
        }
        else if(infix[i] == ')'){
            if(top == -1){
                return 1; // The expression is wrong
            }
            top--;
        }
    }
    if(top != -1){
        return 1; // The expression is wrong
    }

    return 0; // The expression is correct
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
                return "\n***INVALID***\n";
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


void evaluate(char* c){
    float stack[SIZE]; 
    int top=-1;
    for(int i = 0 ; c[i]!='\0' ; i++){
        if(c[i]==' ')
            continue;
        // check if current character is operator or not, if not then push it to stack.
        if(isOperator(c[i]) == 0){
            // subtract it by '0' to get integer value of current character.
            top++;
            stack[top] = c[i]-'0';
        }
        // if current character is operator.
        else{
            float val2 = stack[top--];
            float val1 = stack[top--];
            if(c[i] =='+')
                stack[++top] = (val1 + val2);
            else if(c[i]=='-')
                stack[++top] = (val1 - val2);
            else if(c[i]=='*')
                stack[++top] = (val1 * val2);
            else if(c[i]=='/')
                stack[++top] = (val1 / val2);
            else if(c[i] == '^')
                stack[++top] = (pow(val1,val2) );
        }
    }
    printf("\nEvaluated answer : %f",stack[top]);
}

int main(){
    char infix[SIZE];
    printf("\n***** Remember: Use only single digit Number. *****\n");
    printf("Enter Infix Expression : ");
    fgets(infix, SIZE, stdin); // read string

    // Remove the newline character added by fgets
    infix[strcspn(infix, "\n")] = '\0';

    if (isEmptyExpression(infix)) {
        printf("Invalid! The input expression is empty.\n");
        return 1; // Exit the program with an error code
    }

    // Check for input without operators
    int hasOperators = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isOperator(infix[i])) {
            hasOperators = 1;
            break;
        }
    }

    if (!hasOperators) {
        printf("Invalid! The input expression does not contain any operators.\n");
        return 1; // Exit the program with an error code
    }
    // check for valid parentheses
    if(check_paranthesis(infix)){
        printf("Invalid! The input expression is Not Correct.\n");
        return 1; // Exit the program with an error code
    }    

    // infixToPostfix return the pointer char.
    char* postfix = infixToPostfix(infix);

    printf("Postfix Expression: %s\n", postfix);
    evaluate(postfix);
    free(postfix);
    return 0;
}