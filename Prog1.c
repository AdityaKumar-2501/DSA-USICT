/*  ---------------PROBLEM STATEMENT ---------------
    Implement operations (traverse, insert, delete, linear search ) on an array. 
*/
#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int count){
    printf("\nArray till now: ");
    if(count == 0){
        printf("Array is empty!");
        return;
    }
    for(int i=0; i< count; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[1000];
    int count = 0;
    int choice,data,position;
    char c;

    while (1)
    {
        printf("\n============================ Main Menu =============================\n");
        printf("\nSelect What type of operation you want to do in Array :\n");
        printf("1. Insert at begin\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific Location\n");
        printf("4. Delete at begin\n");
        printf("5. Delete at end\n");
        printf("6. Delete a specific element\n");
        printf("7. Search an element in the array\n");
        printf("8. Display the Array\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("\n***** Please Enter a integer value ****** \n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
        switch (choice)
        {
        case 1:
            printf("Enter the data : ");
            scanf("%d", &data);
            for(int i = count; i > 0 ; i--){
                arr[i] = arr[i-1];
            }
            arr[0] = data;
            count++;
            display(arr,count);
            break;
        case 2:
            printf("Enter the data : ");
            scanf("%d", &data);
            arr[count++] = data;
            display(arr,count);
            break;
        case 3:
        ret:
            printf("Enter the data : ");
            scanf("%d", &data);
            printf("Enter the index(0-based) : ");
            scanf("%d", &position);
            if(position > count){
                printf("\nInvalid index!!\n");
                printf("Renter the data and index (0-based)\n");
                goto ret;
            }
            for(int i = count; i >= position; i--){
                arr[i] = arr[i-1];
            }
            arr[position] = data;
            count++;
            display(arr,count);
            break;
        case 4:
            if(count == 0){
                display(arr,count);
                break;
            }
            for(int i=0; i < count;i++){
                arr[i] = arr[i+1];
            }
            count--;
            display(arr,count);
            break;
        case 5:
            if(count == 0){
                display(arr,count);
                break;
            }
            count--;
            display(arr,count);
            break;
        case 6:
            printf("\n****REMEMBER : it will delete only the first occurence of the number.****\n");
            printf("Enter the data you wish to delete : ");
            scanf("%d",&data);
            int index = -1 ;
            for(int i = 0 ; i < count; i++){
                if(arr[i] == data){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                printf("Element not found\n");
                break;
            }
            for(int i = index; i < count;i++){
                arr[i] = arr[i+1];
            }
            count--;
            display(arr,count);
            break;
        case 7:
            printf("Enter the Element you wish to search : ");
            scanf("%d",&data);
            index = -1;
            for(int i=0; i < count;i++){
                if(arr[i] == data){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                printf("Element not found\n");
                break;
            }
            else{
                printf("The element is at index %d ", index);
            }
            break;
        case 8:
            display(arr,count);
            break;
        case 9:
            printf("Are you sure you want to exit program? (y/n) : ");
            scanf(" %c", &c);
            if (c == 'y'){
                printf("\nExiting the program...\n");
                exit(0);
            }
            else if (c != 'n')
                printf("\nInvalid Input!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}