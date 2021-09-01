#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int close(int arr[],int size){
    if(size == 2){
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

int closest(int arr[],int l,int r){
    if(l-r == 0){
        return 9999;
    }else if(l-r == 1){
        return abs(arr[0]-arr[1]);
    }else{
        int q = (l+r)/2;
        int LClose = closest(arr,l,q);
        int RClose = closest(arr,q+1,r);
        for(int i = l;i<q+1;++i){
        }
        if(LClose < RClose){
            return LClose;
        }else{
            return RClose;
        }
    }
}
/*
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
*/
/*
int closet(int arr[],int size){
    if(size == 1){
        return 9999;
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
        
        for(int i = 0;i<size;++i){
            if(abs(arr[i] - arr[i+1]) < min){
                min = abs(arr[i] - arr[i+1]);
            }
        }

        return min;
    }
}
*/

int closet(int arr[],int l,int r){
    if(l==r){
        return 9999;
    }else if(r-l == 1){
        return abs(arr[0]-arr[1]);
    }else{
        int q = ((l+r)/2);
        int lmin = closet(arr,l,q);
        int rmin = closet(arr,q+1,r);
        int min;
        if(lmin < rmin){
            min = lmin;
        }else{
            min = rmin;
        }
        for(int i = l;i<r;++i){
            if(abs(arr[i] - arr[i+1]) < min){
                min = abs(arr[i] - arr[i+1]);
            }
        }
        return min;
    }
}

int main(void){
    int A[6] = {2,3,1,4,4,6};
    sort(A,A+6);
    int temp = closet(A,0,5);
    printf("%i",temp);
}