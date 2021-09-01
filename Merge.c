#include<stdio.h>

int mergeSort(int A[],int p,int r)
{
    if(p>r){
        return;
    }else{
        int q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int merge(int A[],int p,int q,int r)
{
    int temp[r - p + 1];
    int i = p,j = q+1,c = 0;
    while(p <= q && j <= r)
    {
        if(A[i] > A[j])
        {
            temp[c] = A[j];
        }else{
            temp[c] = A[i];
        }
    }
}

int main(void)
{
    int A[6] = {2,35,56,7,4,2};

}

//Base Case is if length of both right subarray and left subarray reaches to 1
//Problem One Step Smaller is 