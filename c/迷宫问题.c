#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct
{
    int x;
    int y;
    int dir;
}Point;
int maze[MAX][MAX];
int visited[MAX][MAX];
Point stack[MAX *MAX];
int top=-1;
int dx[5]={0,0,1,0,-1};
int dy[5]={0,1,0,-1,0};
void push(Point p)
{
    stack[++top]=p;
}
Point pop()
{
    return stack[top--];
}
int is_empty()
{
    return top==-1;
}
void print_path(int m,int n)
{
    for(int i=0;i<top;i++)
    {
        printf("(%d,%d,%d)",stack[i].x,stack[i].y,stack[i].dir);
    }
    printf("(%d,%d,0)\n",stack[top].x,stack[top].y);
}
int solve_maze(int m,int n)
{
    if(maze[1][1]==1)
    return 0;
    Point start={1,1,1};
    push(start);
    visited[1][1]=1;
    while(!is_empty())
    {
        Point cur=stack[top];
        int x=cur.x,y=cur.y,d=cur.dir;
        if(x==m&&y==n)
        {
            return 1;
        }
        int found=0;
        for(int dir=d;dir<=4;dir++)
        {
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&maze[nx][ny]==0&&visited[nx][ny]==0)
            {
                stack[top].dir=dir;
                Point next={nx,ny,1};
                push(next);
                visited[nx][ny]=1;
                found=1;
                break;
            }
        }
        if(!found)
        {
            pop();
        }
    }
    return 0;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    char line[MAX];
    for(int i=1;i<=m;i++)
    {
        scanf("%s",line);
        for(int j=1;j<=n;j++)
        {
            maze[i][j]=line[j-1]-'0';
            visited[i][j]=0;
        }
    }
    if(solve_maze(m,n))
    {
        print_path(m,n);
    }
    else
    {
        printf(" ");
    }
    return 0;
}