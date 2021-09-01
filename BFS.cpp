#include<iostream>
#include<queue>
using namespace std;

const int K = 5;//Here K is the Total Number of Vertices Present in The Graph
int count[K];//Representing the Array of Vertices Where we visit all The Vertices While Implementing Breadth First Search

int visited[K];//Keeps Track of Node is Visited In The Graph or Not
int parent[K];//Parent Array Keeps Track of The Parent Node
int level[K];//Level of Each Node is Accessed Through Level Array
int path[K] = {0};//Stores The Path

void printarr(int arr[],int size)
{
    for(int i = 0;i<size;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int check(int arr[]){
    //Checks if All Vertices are Visited
    int count = 0;
    for(int i = 0;i<K;++i)
    {
        if(arr[i] == 1)
        {
            count++;
        }
    }
    if(count == K)
    {
        return 1;
    }else{
        return 0;
    }
}


void BFS(int A[K][K],int s)
{
    path[K] = {0};
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
    path[0] = s;
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
                path[u] = (i+1);
                u++;

            }
        }

    }

    if(check(visited) == 1)
    {
        for(int i = 0;path[i] != 0;++i){
            cout<<path[i]<<"->";
        }
    }

}

int main()
{

    //Total Verticies in The Graph are K
    
    //Adjaency Matrix Defination
    int Graph[K][K];
    for(int i = 0;i<K;++i)
    {
        for(int j = 0;j<K;++j)
        {
            if(i == j){
                //First Condition for r == c
                Graph[i][j] = 0;
            }else{
                //Second Condition for r != c
                Graph[i][j] = abs((i-(2*j))*(i-(3*j)))%13;
            }
        }
    }
    
    //Printing The Adjacency Matrix
    for(int k = 0;k<K;++k)
    {
        for(int q = 0;q<K;++q)
        {
            cout<<Graph[k][q]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    //Each Vertice is Labeled 1 to N for their representation 
    for(int i = 1;i<=K;++i)
    {
        path[K] = {0};
        BFS(Graph,i);
        cout<<"\n";
    }
}