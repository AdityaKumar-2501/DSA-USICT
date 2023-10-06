#include<stdio.h>

int main(){

    int row , col;

    printf("Enter the Numbers of the rows : ");
    scanf(" %d",&row);

    printf("Enter the Number of the columns : ");
    scanf(" %d",&col);

    int sparse[row][col];
    int totalElements = row * col;
    int nonzeroElements = 0;

    printf("Enter the data in the sparse matrix\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d",&sparse[i][j]);
            if(sparse[i][j] != 0){
                nonzeroElements++;
            }
        }
    }

    printf("\n********* Sparse Matrix ****************\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }

    if(nonzeroElements > totalElements/4){
        printf("\n***********ERROR*********\n");
        printf("\nGiven matrix is NOT sparse matrix!!\n");
    }
    else{
        int tripletRow = nonzeroElements+1;
        int triplet[tripletRow][3];
        triplet[0][0] = row;
        triplet[0][1] = col;
        triplet[0][2] = nonzeroElements;
        int k = 1;

        for(int i = 0 ; i< row; i++){
            for(int j = 0 ; j< col; j++){
                if(sparse[i][j] != 0){
                    triplet[k][0] = i;
                    triplet[k][1] = j;
                    triplet[k][2] = sparse[i][j];
                    k++;
                }
            }
        }

        printf("\n********* Triplet Matrix ****************\n");
        for(int i = 0 ; i< tripletRow ; i++){
            for(int j = 0 ; j<3;j++){
                printf("%d ", triplet[i][j]);
            }
            printf("\n");
        }
    }


    return 0;
}