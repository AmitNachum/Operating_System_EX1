#include "SPT.h"


int main(){

printf("===== Dijkstra Algorithm =====\n\n");
    int graph[V][V];

    for (int v = 0; v < V; v++)
    {
        int weight;
        for (int u = 0; u < V; u++)
        {
            while (true){
            int option;
            printf("1)Please enter a positive Integer\n2)Set edge to Infinity\n(1 or 2)\n\n");

           if (scanf("%d",&option) != 1 || option != 1 && option != 2)
           {
            printf("Invalid input,please try again.\n\n");
            int ch;
            while (ch = getchar() != '\n' && ch != EOF);
            continue;
           }


            if (option == 2)
            {
                printf("Edge (%d,%d) = INFINITY.\n\n",v,u);
                weight = INT_MAX;
                break;
            }

            
            if (option == 1)
            {
            printf("Enter the desired Weight:\n\n");
            scanf("%d",&weight);
            if (weight < 0)
            {
                printf("Weight must be a non negative Integer\n\n");
                int ch;
                while (ch = getchar() != '\n' && ch != EOF);
                continue;
            }
            else break;
        }
            
        }
        graph[u][v] = weight;
            
        }

        
    }

int SorF = -1;
int *status = &SorF;
dijkstra(graph,0,status);
printf("\n");

if (*status == -1)
{
    printf("Error,Has occured.\nExiting...\n\n");
}
else
printf("SUCCESS!!\n\n");




    return 0;
    
}