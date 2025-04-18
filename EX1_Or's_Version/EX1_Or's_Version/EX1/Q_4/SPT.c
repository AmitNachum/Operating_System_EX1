#include "SPT.h"

int minDistance(int dist[],bool sptSet[]){
    int min = INT_MAX;
    int minIndex = 0;

    for (int i = 0; i < V; i++)
    {
        if (!sptSet[i] && dist[i] <= minIndex) 
        {
            min = dist[i];
            minIndex = i;
        }

    }
    return minIndex;
    
}

void printSolution(int dist[])
{
    printf("\nVertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t %d\n", i, dist[i]);
}


void dijkstra(int graph[V][V],int src,int *status){

    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V ; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;

    }

    dist[src] = 0;



    for (int i = 0; i < V - 1; i++)
    {
        
        int u = minDistance(dist,sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] < 0)
            {
                return;
            }
            if (graph[u][v] == INT_MAX)
            {
                continue;
            }
            
            
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
          

            }
            
        }
    }
    *status = 1;
    printSolution(dist);
    
}
