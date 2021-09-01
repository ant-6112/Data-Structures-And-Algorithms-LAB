#include<iostream>
#include<queue>
using namespace std;

const int K = 5;//Here K is the Total Number of Vertices Present in The Graph
int count[K];//Representing the Array of Vertices Where we visit all The Vertices While Implementing Breadth First Search

int visited[K];//Keeps Track of Node is Visited In The Graph or Not
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
            if(A[i][k] == 1 && visited[i] == 0)
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

    //Total Verticies in The Graph
    int Verticies = K;

    //Adjaency Matrix Defination
    int Graph[Verticies][Verticies];
    for(int i = 0;i<Verticies;++i)
    {
        for(int j = 0;j<Verticies;++j)
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
    for(int k = 0;k<Verticies;++k)
    {
        for(int q = 0;q<Verticies;++q)
        {
            cout<<Graph[k][q]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    BFS(Graph,1);
    /*
    //Each Vertice is Labeled 1 to N for their representation 
    for(int i = 1;i<=Verticies;++i)
    {
        BFS(Graph,i);
    }
    */
    
}