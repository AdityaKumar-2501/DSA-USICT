#include<stdio.h>

int main(){
    int x;
    printf("Welcome\nEnter the size: ");
    scanf("%d",&x);
    int arr[x];
    for (int i = 0; i < x; i++)
    {
        printf("enter the value :");
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < x; i++){
        printf("%d ",arr[i]);
    }
    
    
    return 0;
}