/*  ---------------PROBLEM STATEMENT ---------------
   Implement evaluation of postfix notation using stacks.
*/

#include <stdio.h>
#include "infixTopostfix.h"

int main(){
    char* ans = infixToPostfix("(a*b/e-d)/(f+g^h)");
    printf("%s\n", ans);
    free(ans);
    
    return 0;
}