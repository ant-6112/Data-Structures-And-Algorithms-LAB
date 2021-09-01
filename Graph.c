#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
 
void dijkstra(int G[MAX][MAX],int n,int startnode);
 
int main()
{
	int G[MAX][MAX],i,j,n,u;
	printf("Enter No. Of Vertices:");
	scanf("%d",&n);
	printf("\nEnter The Adjacency Matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	
	printf("\nEnter The Starting Node:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	
	return 0;
}
 
void dijkstra(int G[MAX][MAX],int n,int startnode)
{
 
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindist,j,i,k;
	
	//pred[] Stores The Predecessor Of Each Node
	//Count Are The Number Of Nodes Visited So Far
	//Create The Cost Matrix

	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
			if(G[i][k]==0){
				cost[i][k]=INFINITY;
            }else{
				cost[i][k]=G[i][k];
            }
        }
	}

	//Initialize pred[] , distance[] , visited[]

	for(i=0;i<n;i++)
	{
        visited[i] = 0;
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
	}
	
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	
	while(count<n-1)
	{
		mindist = INFINITY;
		
		//J Gives Node at Minimum Distance
		for(i=0;i<n;i++)
			if(distance[i]<mindist && !visited[i])
			{
				mindist = distance[i];
				j = i;
			}
			
			//Check If a Path Through Exists To J	
        	
			visited[j] = 1;

			for(i=0;i<n;i++){
				if(!visited[i])
					if(mindist + cost[j][i]<distance[i])
					{
						distance[i] = mindist + cost[j][i];
						pred[i] = j;
					}
            }
		count++;
	}
 
    for(i=0;i<n;i++)
		if(i != startnode)
		{
			printf("\nDistance Of Node %d = %d",i,distance[i]);
			printf("\nPath = %d",i);
			
			j = i;
			do
			{
				j = pred[j];
				printf("<-%d", j);
			}while(j != startnode);
	}
}