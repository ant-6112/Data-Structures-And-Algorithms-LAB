#include<bits/stdc++.h>
using namespace std;

void MergeSort(int A[],int str,int end){
    if(str<end){
        int mid = (str+end)/2;
        MergeSort(A,str,mid); //No Need For Calling The List In Recursive Arrays As Arguments
        MergeSort(A,mid+1,end);
    }else if(str == end){
        
    }
}