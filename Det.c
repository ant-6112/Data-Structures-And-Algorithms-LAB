#include<stdio.h>
#include<stdlib.h>

void inputM(int *A[],int n)
{
    for(int i = 0;i<n;i++)
    {
        A[i] = (int *)malloc((n-i)*sizeof(int));
        for(int j = 0;j<n-i;j++)
        {
            int temp;
            printf("Enter A[%i][%i] : ",i,j);
            scanf("%i",&temp);
            *(*(A + i) + j + i) = temp;
            printf("\n");
        }
    }
}

void printM(int *A[],int n)
{
    for(int k = 0;k<n;k++)
    {
        for(int p = 0;p<n;p++)
        {
            if(p >= k){
                printf("%i ",*(*(A + k) + p));
            }else if(p<k){
                printf("%i ",*(*(A + p) + k));
            }
        }
        printf("\n");
    }
}

void Multiply(int *A[],int *B[],int n)
{
    int mul[n][n];
    int j;
    for(int k = 0;i<n;++i)
    {
        mul[k][p] = 0;
        for(p = 0;j<n;j++)
        {
            mul[i][j]+= *(*(A+k)+p) * *()
        }
    }
}

int main()
{
    //Making a Array of Pointers Where each element points to a Array of Block of Memmory of Varying Sizes
    //We are ONLY Taking Input For The Upper Right Entries and Only Storing Them in a Row-Major Arrangement
    int n;
    printf("Enter n : ");
    scanf("%i",&n);
    printf("\n");
    int *A[n];
    int *B[n];
    inputM(A,n);
    printM(A,n);
    //While Taking Input Only Type The Upper Right Entries Of The Matrix
}