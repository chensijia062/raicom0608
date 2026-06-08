#include<stdio.h>
#include<stdlib.h>

int g[10005][10005]={0};
int color[10005][5]={0};
int ret[10005]={0};
int main()
{
    int n,m;
    
    
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=g[y][x]=1;
    }
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            if(color[i][j]==0){
                ret[i]=j;
                for(int k=1;k<=n;k++){
                    if(g[i][k]){
                        color[k][ret[i]]=1;
                    }
                }
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ret[i]);
    }
    return 0;
}