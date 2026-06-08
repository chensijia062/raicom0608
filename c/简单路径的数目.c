#include<stdio.h>
#include<stdlib.h>

int vd[1005]={0};
int cnt=0,n,M,d=1;
int g[1005][1005]={0};
void dfs(int len,int start){
    
    if(len==M){
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(g[start][i]&&vd[i]==0){
            vd[i]=1;
            for(int k=0;k<g[start][i];k++){
                dfs(len+1,i);
                
            }
           vd[i]=0;
        }
    }
}
int main()
{
    int m,start;
    scanf("%d%d%d%d",&n,&m,&start,&M);
    
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]++;
        
    }
    vd[start]=1;
    dfs(0,start);
    
    printf("%d",cnt);
    return 0;
}