/*  ---------------PROBLEM STATEMENT ---------------
    Make a menu driven program to perform various sorting techniques
    -insertion, merge, quick.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void mainMenu();

void display(int arr[], int n){
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


void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    
    int n = high - low + 1;
    int ans[n];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            ans[k] = arr[i];
            i++;
            k++;
        } else {
            ans[k] = arr[j];
            j++;
            k++;
        }
    }

    // Copy the remaining elements from the left array
    while (i <= mid) {
        ans[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements from the right array
    while (j <= high) {
        ans[k] = arr[j];
        j++;
        k++;
    }

    // Copy all the values from the ans array to the actual array
    for (int i = low; i <= high; i++) {
        arr[i] = ans[i];
    }
}


void mergeSort(int arr[], int low, int high){

    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l+1;
    int j = h;
    while(i<=j){
        while(arr[i]<= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swaping the pivot with jth index element
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[],int l,int h){
    if(l<h){
        int partitionIndex = partition(arr,l,h);
        quickSort(arr,l, partitionIndex-1);
        quickSort(arr,partitionIndex+1,h);
    }
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
        printf("\n1. Insertion Sort\n2. Merge Sort\n3. Quick Sort\n4. Exit\n");
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
            display(arr,n);
            break;
        case 2:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            mergeSort(arr,0,n-1);
            display(arr,n);
            break;
        case 3:
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            printf("Enter the Value of the array : ");
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }
            quickSort(arr,0,n-1);
            display(arr,n);
            break;
        case 4:
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