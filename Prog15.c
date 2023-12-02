/*  ---------------PROBLEM STATEMENT ---------------
    Make a menu driven program to perform various sorting techniques
    -insertion, merge, heap, quick, counting, radix, bucket.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void mainMenu();

void print(int arr[], int n){
    printf("\nArray After Sorting : ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void mergeSort(int arr[], int n){
    printf("NOT done yet\n");
}

void heapSort(int arr[], int n){
    printf("NOT done yet\n");
    
}

void quickSort(int arr[], int n){
    printf("NOT done yet\n");
    
}

void countingSort(int arr[], int n){
    printf("NOT done yet\n");
    
}

void radixSort(int arr[], int n){
    printf("NOT done yet\n");
    
}

void bucketSort(int arr[], int n){
    printf("NOT done yet\n");
    
}





void mainMenu()
{
    int choice;
    char c;
    int n;
    int arr[SIZE];

    while (1)
    {
        printf("\n************* MAIN MENU ****************\n");
        printf("\nChoose any of the following Sorting technique:");
        printf("\n1. Insertion Sort\n2. Merge Sort\n3. Heap Sort\n4. Quick Sort\n5. Counting Sort\n6. Radix Sort\n7. Bucket Sort\n8. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            insertionSort(arr,n);
            print(arr,n);
            break;
        case 2:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            insertionSort(arr,n);
            break;
        case 3:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            insertionSort(arr,n);
            break;
        case 4:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            insertionSort(arr,n);
            break;
        case 5:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            insertionSort(arr,n);
            break;
        case 6:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            insertionSort(arr,n);
            break;
        case 7:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            insertionSort(arr,n);
            break;
        case 8:
            printf("\nAre you sure you want to exit program? (y/n) : ");
            scanf(" %c", &c);
            if (c == 'y')
                exit(0);
            else if (c != 'n')
                printf("\nInvalid Input!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main()
{
    mainMenu();
    return 0;
}