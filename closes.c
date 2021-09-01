#include<stdio.h>
#include <stdlib.h>

#define INFINITY 999

int close(int arr[],int size){
    if(size == 3){
        return abs(arr[0] - arr[1]);
    }else{
        int temparr1[(size)/2];
        for(int i = 0;i<(size)/2;++i){
            temparr1[i] = arr[i];
        }
        int temparr2[(size) - (size/2)];
        for(int i = (size/2)+1;i<(size);++i){
            temparr2[i] = arr[i];
        }
        int leftmin = close(temparr1,size/2);
        int rightmin = close(temparr2,size - (size/2));
        if(leftmin < rightmin){
            return abs(leftmin);
        }else{
            return abs(rightmin);
        }
    }
}

int recu(int arr[],int size){
    if(size == 2){
        return abs(arr[0] - arr[1]);
    }else{
        int temparr1[size-1];
        for(int i = 0;i<size-1;++i){
            temparr1[i] = arr[i+1];
        }
        int min = recu(temparr1,size-1);
        for(int i = 1;i<size;++i){
            if(abs(arr[0]-arr[i]) < min){
                min = abs(arr[0]-arr[i]);
            }
        }
        return min;
    }
}

int closet(int arr[],int size){
    if(size == 1){
        return INFINITY;
    }else if(size == 2){
        return abs(arr[0]-arr[1]);
    }else{
        int temparr1[(size)/2];
        for(int i = 0;i<(size)/2;++i){
            temparr1[i] = arr[i];
        }
        int temparr2[(size) - (size/2)];
        for(int i = (size/2);i<(size);++i){
            temparr2[i-(size/2)] = arr[i];
        }
        int lmin = closet(temparr1,size/2);
        int rmin = closet(temparr2,size-(size/2));
        int min;
        if(lmin < rmin){
            min = lmin;
        }else{
            min = rmin;
        }
        /*for(int i = 0;i<size/2;++i){
            for(int j = size/2;j<size;++j){
                if(abs(arr[i]-arr[j]) < min){
                    min = abs(arr[i]-arr[j]);
                }
            }
        }*/
        return min;
    }
}

int Maxi(int arr[],int l,int r){
    if(size == 1){
        return arr[0];
    }else{
        int lmax = Max(arr,0,r/2);
        int rmax = Max(arr,r/2,r);

        if(Max)
    }
}

int main(void){
    int arr[6] = {2,3,1,4,5,9};
    printf("%i",recu(arr,6));
}