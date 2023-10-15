/*  ---------------PROBLEM STATEMENT ---------------
   Implement evaluation of postfix notation using stacks.
*/

#include <stdio.h>
#include<string.h>
#include<math.h>
#include "infixTopostfix.h"
#define SIZE 100


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

    // Adding sentinal to infix expression
    int length = strlen(infix);
    if (length < SIZE - 1) {
        infix[length] = ')';
        infix[length + 1] = '\0'; // Ensure the string is null-terminated
    }else {
        printf("Infix expression is too long to append ')'\n");
    }
    // infixToPostfix return the pointer char.
    char* postfix = infixToPostfix(infix);
    printf("Postfix Expression: %s\n", postfix);
    evaluate(postfix);
    free(postfix);
    return 0;
}