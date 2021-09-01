#include<stdio.h>

void input(int A[], unsigned int n)
{
    for(int i=0;i<n;i++){
        printf("Enter A[%d] : ",i);
        scanf("%d", &A[i]);
    }
}

void print(int A[], unsigned int n)
{
    for(int i=0;i<n;i++){
        printf(" %d ",A[i]);
    }
}

int BinarySearch(int A[], int l_idx, int r_idx, int key)
{
    if(l_idx<=r_idx){
        int m_idx = l_idx + ((r_idx-l_idx)/2);
        //Prevents Overflow
        if(A[m_idx]>key){
            return BinarySearch(A, l_idx, m_idx-1, key);
        }else if(A[m_idx]<key)
        {
            return BinarySearch(A, m_idx+1, r_idx, key);
        }else if(A[m_idx]==key)
        {
            return m_idx;
        }
        
    }
    return -1;
    //key is not found 
}

int BinarySearchI(int A[], int l_idx, int r_idx, int key)
{
    while(l_idx<=r_idx){
        int m_idx = l_idx + ((r_idx-l_idx)/2);
        //Prevents Overflow 
        if(A[m_idx]>key){
            r_idx = m_idx-1;
        }else if(A[m_idx]<key)
        {
            l_idx=m_idx+1;
        }else if(A[m_idx]==key)
        {
            return m_idx;
        }
        
    }
    return -1;
    //Key Is Not Found
}

int main()

{
    unsigned int n;
    printf("Enter n:");
    scanf("%u", &n);
    
    int A[n];
    input(A, n);
    print(A, n);
    
    int key;
    printf("\nEnter key: ");
    scanf("%d", &key);
    
    int RSA = 0;
    int idx;
    
    if(RSA == 0){

        printf("Result from Binary Search (Recursive)");
        idx = BinarySearch(A, 0, n-1, key);
        if(idx == -1){
            printf("Element is not present in the array.\n");
        }else
        {
            printf("Element is present at position %d \n",idx);
        }

        printf("Result from Binary Search (Iterative)");
        idx = BinarySearchI(A, 0, n-1, key);
        if(idx == -1){
            printf("Element is not present in the array.\n");
        }else{
            printf("Element is present at position %d\n",idx);
        }
    }
    return 0;
}