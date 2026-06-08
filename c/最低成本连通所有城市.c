#include<stdio.h>
#include<stdlib.h>

struct edge{
    int x,y,cost;
};
int fa[10005];
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        return fa[x]=find(fa[x]);
    }
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy){
        return;
    }else{
        fa[fy]=fx;
        return;
    }
}
int cmp(const void*a,const void* b){
    struct edge* x=(struct edge*)a;
    struct edge* y=(struct edge*)b;
    if(x->cost==y->cost){
        if(x->x==y->x){
            return x->y-y->y;
        }else{
            return x->x-y->x;
        }
    }else{
        return x->cost-y->cost;
    }
}
int main()
{
    int n,m,cnt=0;
    scanf("%d%d",&n,&m);
    struct edge g[n+1];
    int gsize=0;
    
    for(int i=0;i<m;i++){
        int x,y,cost;
        scanf("%d%d%d",&x,&y,&cost);
        g[gsize].x=x;
        g[gsize].y=y;
        g[gsize].cost=cost;
        gsize++;
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    qsort(g,gsize,sizeof(struct edge),cmp);
    int ret=0;
    for(int i=0;i<m;i++){
        int x=g[i].x,y=g[i].y;
        int fx=find(x),fy=find(y);
        if(fx!=fy){
            ret+=g[i].cost;
            merge(x,y);
            cnt++;
        }
    }
    if(cnt!=n-1){
        printf("-1");
        return 0;
    }
    printf("%d",ret);
    return 0;
}