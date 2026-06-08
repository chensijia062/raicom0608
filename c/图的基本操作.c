#include<stdio.h>

#define MAX 105

int g[MAX][MAX];
int degree[MAX];
int vertex[MAX]; 
int findIndex(int x,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(vertex[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&vertex[i]);
    }
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int u=findIndex(x,m);
        int v=findIndex(y,m);
        g[u][v]=1;
        g[v][u]=1;
        degree[u]++;
        degree[v]++;
    }
    printf("Please input the total number of vertices and the total number of edges, separated by a space:\n");
    printf("Please input the names of the vertices, such as 1:\n");
    printf("Please input the vertices to which the edge is attached, such as 1 2:\n\n");
    printf("The adjacency matrix of the undirected network G is:\n");
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d  ",g[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=m;i++)
    {
        printf("The degree of vertex %d is %d\n",vertex[i],degree[i]);
    }
    return 0;
}