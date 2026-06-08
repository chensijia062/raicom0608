#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int idx;

    char name;

    struct node* next;
};

int vexnum,edgenum;

// 邻接表头结点
struct node* v[105];

int vd[105]={0};

int fa[105];


// 查找顶点下标
int find(char x)
{
    for(int i=0;i<vexnum;i++)
    {
        if(v[i]->name==x)
        {
            return i;
        }
    }

    return -1;
}


// 并查集查找
int findfa(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    else
    {
        fa[x]=findfa(fa[x]);

        return fa[x];
    }
}


// 合并集合
void merge(int x,int y)
{
    int fx=findfa(x);

    int fy=findfa(y);

    if(fx!=fy)
    {
        fa[fy]=fx;
    }
}


// DFS
void dfs(int x)
{
    if(vd[x]==0)
    {
        printf("%c ",v[x]->name);

        vd[x]=1;

        struct node* temp=v[x]->next;

        while(temp)
        {
            dfs(temp->idx);

            temp=temp->next;
        }
    }
}


int main()
{
    scanf("%d%d",&vexnum,&edgenum);

    // 输入顶点
    for(int i=0;i<vexnum;i++)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));

        char x;

        scanf(" %c",&x);

        temp->idx=i;

        temp->name=x;

        temp->next=NULL;

        v[i]=temp;
    }

    // 初始化并查集
    for(int i=0;i<vexnum;i++)
    {
        fa[i]=i;
    }

    // 输入边
    for(int i=0;i<edgenum;i++)
    {
        char s[3];

        scanf("%s",s);

        int a=find(s[0]);

        int b=find(s[1]);

        // a -> b
        struct node* cur1=(struct node*)malloc(sizeof(struct node));

        cur1->idx=b;

        cur1->next=v[a]->next;

        v[a]->next=cur1;

        // b -> a
        struct node* cur2=(struct node*)malloc(sizeof(struct node));

        cur2->idx=a;

        cur2->next=v[b]->next;

        v[b]->next=cur2;

        merge(a,b);
    }

    int first,second;

    scanf("%d%d",&first,&second);

    // 输出
    printf("please input the vexnum and arcnum\n");

    printf("vexnum=\n");

    printf("arcnum=\n\n");

    printf("enter the vexdata\n\n");

    printf("enter the edge\n");

    for(int i=0;i<edgenum;i++)
    {
        printf("input %d edge:",i+1);
    }

    printf("\n");

    printf("-------------------------------\n");

    // 输出邻接表
    for(int i=0;i<vexnum;i++)
    {
        printf("   AdjList[%d]   ",i);

        printf("%c",v[i]->name);

        struct node* temp=v[i]->next;

        while(temp)
        {
            printf("-->%d",temp->idx);

            temp=temp->next;
        }

        printf("\n");
    }

    printf("\n");

    // DFS
    dfs(0);

    printf("\n");

    // 判断连通性
    printf("%d %d ",first,second);

    if(findfa(first)==findfa(second))
    {
        printf("connect");
    }
    else
    {
        printf("unconnect");
    }

    return 0;
}