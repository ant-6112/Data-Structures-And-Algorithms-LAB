#include<iostream>
#include<queue>
using namespace std;

const int K = 5;//Here K is the Total Number of Vertices Present in The Grap
int count[K];//Representing the Array of Vertices Where we visit all The Vertices While Implementing Breadth First Search

int visited[K];//Keeps Track of Node is Visited In The Grap or Not
int parent[K];//Parent Array Keeps Track of The Parent Node
int level[K];//Level of Each Node is Accessed Through Level Array

//This is To Print The Three Arrays Defined Above
void printarr(int arr[],int size)
{
    for(int i = 0;i<size;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void BFS(int A[K][K],int s)
{
    for(int i = 0;i<K;++i)
    {
        visited[i] = 0;
        parent[i] = -1;
        level[i] = -1;
    }
    queue<int> Q;
    visited[s-1] = 1;
    Q.push(s);
    level[s-1] = 0;
    cout<<s<<"->";
    while(Q.empty() != 1)
    {
        int j = Q.front();
        Q.pop();
        int k = j-1;
        for(int i = 0;i<K;++i)
        {
            if(A[i][k] != 0 && visited[i] == 0)
            {
                Q.push(i+1);
                visited[i] = 1;
                parent[i] = j;
                level[i] = level[k] + 1;
                cout<<k<<"->";
            }
        }
    }

}

int Check(int arr[]){
    //Checks if All Vertices are Visited
    int i;
    for(i = 0;i<K;++i)
    {
        if(i == 1){
            continue;
        }
        break;
    }
    if(i == K-1)
    {
        return i;
    }else{
        return 0;
    }
}

int main()
{

    //Total K in The Grap is K

    //Adjaency Matrix Defination
    int Grap[K][K] = {0};
    for(int i = 0;i<K;++i)
    {
        for(int j = 0;j<K;++j)
        {
            if(i == j){
                //First Condition for r == c
                Grap[i][j] = 0;
            }else{
                //Second Condition for r != c
                Grap[i][j] = abs((i-(2*j))*(i-(3*j)))%13;
            }
        }
    }
    
    //Printing The Adjacency Matrix
    for(int k = 0;k<K;++k)
    {
        for(int q = 0;q<K;++q)
        {
            cout<<Grap[k][q]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    BFS(Grap,1);
    /*
    //Each Vertice is Labeled 1 to N for their representation 
    for(int i = 1;i<=K;++i)
    {
        BFS(Grap,i);
    }
    */
    
}