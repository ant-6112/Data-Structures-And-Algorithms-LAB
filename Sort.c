#include<stdio.h>

int Max(int arr[],int l,int r){
    if(l == r){
        return arr[l];
    }else{
        int q = (l+r)/2;
        int LMax = Max(arr,l,q);
        int RMax = Max(arr,q+1,r);
        if(LMax > RMax){
            return LMax;
        }else{
            return RMax;
        }
    }
}

int main(void){
    int A[] = {4,45,2763,5,3,223};
    printf("%i",Max(A,0,5));
}
