#include<bits/stdc++.h>
using namespace std;

#define INFINITY 99
#define MAX 10

void dijkstra()
{
    int G[MAX][MAX], i, j, n, u;
    printf("\nEnter the no. of vertices:: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix::");
    for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    scanf("%d", &G[i][j]);
    printf("\nEnter the starting node:: ");
    scanf("%d", &u);

    int startnode = u;

    int cost[MAX][MAX],distance[MAX],pred[MAX],visited[MAX];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }

        for(int i=0;i<n;i++)
        {
            distance[i] = cost[startnode][i];
            pred[i] = startnode;
            visited[i] = 0;
        }

        distance[startnode] = 0;
        visited[startnode] = 1;
        int count =1;
        int mindist,nextnode;
        while(count<n-1)
        {
            mindist = INFINITY;
            for(i=0;i<n;i++)
            {
                if(distance[i]<mindist && !visited[i])
                {
                    mindist=distance[i];
                    nextnode = i;
                }
            }

            visited[nextnode]=1;

            for(i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    if(mindist+cost[nextnode][i]<distance[i])
                    {
                        distance[i]= mindist+cost[nextnode][i];
                        pred[i] = nextnode;
                    }    
                }
            }
            count++;
        }

        for(int i=0;i<n;i++)
        {
            if(i!=startnode)
            {
                cout<<"Distance of "<<i<<" "<<distance[i]<<"\n";
            }
            j=i;
            do
            {
                j=pred[j];
                cout<<i<<"<-"<<j<<"\n";
            } while (j!=startnode);
            
        }

    }

}

int main()
{
    dijkstra();
}