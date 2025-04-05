#ifndef SPT_H
#define SPT_H
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 3
int minDistance(int dist[],bool sptSet[]);
void printSolution(int dist[]);
void dijkstra(int graph[V][V],int src,int *status);

#endif
