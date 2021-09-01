#include<iostream>
#include<queue>
using namespace std;

const int K = 7;//Here K is the Total Number of Vertices Present in The Graph

int visited[K];//Keeps Track of Node is Visited In The Graph or Not
int parent[K];//Parent Array Keeps Track of The Parent Node
int level[K];//Level of Each Node is Accessed Through Level Array

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
    int u = 1;
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
            }
        }

    }

}

int main()
{
    //Adjaency Matrix Defination
    int Graph[K][K] = {
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0}
    };
    //Each Vertice is Labeled 1 to N for their representation 
    BFS(Graph,1);
}