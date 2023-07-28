#include <stdio.h>
#include <stdlib.h>
int a[10][10],n,i,j,source;
int visited[10];
void create()
{
    printf("\nEnter the no. of vercites of the digraph : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix of thr graph : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void bfs()
{
    int q[10],u,f=0,r=-1;
    printf("\nEnter the source vertex to find other nodes reachable or not : ");
    scanf("%d",&source);
    q[++r]=source;
    visited[source]=1;
    printf("\nReachable vertices are : ");
    while(f<=r)
    {
        u=q[f++];
        for(i=1;i<=n;i++)
        {
            if(a[u][i]==1 && visited[i]==0)
            {
                q[++r]=i;
                visited[i]=1;
                printf("\t%d",i);
            }
        }
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Create Graph\n2. BFS\n3. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : bfs();
                     for(i=1;i<=n;i++)
                     {
                         if(visited[i]==0)
                         {
                             printf("\nThe vertex that is not reachable : %d ",i);
                         }
                     }
                     break;
            case 3 : exit(0);
        }
    }
}

