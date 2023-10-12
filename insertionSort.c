/*
    The below code implements the insertion sort algorithm to sort
    an array of integers in ascending order.
*/

#include<stdio.h>


int main(){
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements of the array\n");
    for(int i=0; i<n; i++){
        scanf(" %d",&arr[i]);
    }

    // insertion sort       
    for (int step = 1; step < n; step++) {
    int key = arr[step];
    int j = step - 1;
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }


    printf("\nArray after Insertion Sort : ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}