#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,weight;
};

struct Graph
{
    int v,e;
    struct Edge* edge;
};

struct Graph* createGraph(int v,int e)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v=v;
    graph->e=e;
    graph->edge=(struct Edge*)malloc(graph->e*sizeof(struct Edge));
    return graph;
};

void printArr(int dist[],int n)
{
    cout<<"Distance from source\n";
    for(int i=0;i<n;i++)
        cout<<i<<" "<<dist[i];
}

void BellmanFord(struct Graph* graph,int src)
{
    int v = graph->v;
    int e = graph->e;
    int dist[v];

    for(int i=0;i<v;i++)
        dist[i]=INT_MAX;

    dist[src]=0;

    for(int i=1;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u = graph->edge[j].src;
            int v1 = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+weight < dist[v1])
                dist[v1]=dist[u]+weight;
        }
    }
    for(int i=0;i<e;i++)
    {
        int u=graph->edge[i].src;
        int v1 = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if(dist[u]!=INT_MAX && dist[u]+weight < dist[v1])
            cout<<"No negative cycle in graph\n";
    }
    printArr(dist,v);
    return;
}

int main()
{
    int v,e;
    printf("\nEnter the no. of vertics: ");
    scanf("%d", &v);
    printf("\nEnter the no. of Edges: ");
    scanf("%d", &e);

    struct Graph* graph = createGraph(v,e);
    int p,q,r;
    int i=0;
    while(i<e)
    {
        printf("for %d edge Enter the source:", i);
        scanf("%d",&p);
        graph->edge[i].src = p;
        printf("Enter the destination:");
        scanf("%d", &q);
        graph->edge[i].dest =q;
        printf("Enter the weight:");
        scanf("%d",&r);
        graph->edge[i].weight = r;
        i++;
    }
    BellmanFord(graph, 0);
    return 0;
}
