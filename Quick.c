#include<stdio.h>

void printArray(char array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%c  ", array[i]);
  }
  printf("\n");
}

void swap(char *a, char *b) {
  char t = *a;
  *a = *b;
  *b = t;
}

int part(char A[],int r,int l)
{
    int piv = A[l];
    int i = r - 1;
    for(int j = r;j<=(l-1);j++)
    {
        if(A[j] <= piv)
        {
            i++;
            swap(&A[i],&A[j]);
            printArray(A,l);
        }
        
    }
    swap(&A[i+1],&A[l]);
    return i+1;
}

void Quick(char A[],int r,int l)
{
    if(r < l)
    {
        int piv = part(A,r,l);
        Quick(A,r,piv-1);
        Quick(A,piv+1,l);
    }
}

int main(void){

    int B[] = {3,7,2,52,71,18,13};
    char A[] = {'D','R','A','W','E','R'};
    Quick(A,0,5);
    printArray(A,6);
}