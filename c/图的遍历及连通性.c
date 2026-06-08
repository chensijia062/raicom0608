#include<stdio.h>
#include<stdlib.h>

int g[10005][10005];
int vd[10005]={0};
int cnt=0;
int n;
void dfs(int x){
    if(vd[x]){
        return;
    }
    vd[x]=1;
    for(int i=1;i<=n;i++){
        if(g[x][i]&&vd[i]==0){
            dfs(i);
        }
    }
}
int main()
{
    
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        if(vd[i]==0){
            cnt++;
            dfs(i);
        }
    }
    printf("%d",cnt);
    return 0;
}