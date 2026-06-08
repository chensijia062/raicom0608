#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n,path[105]={0};
int min(int x,int y){
    return x<y?x:y;
}
int prim(int g[][105],int start){
    int mindist[105],vd[105]={0};
    for(int i=0;i<=n;i++){
        mindist[i]=INT_MAX;
    }
    mindist[start]=0;
    for(int i=1;i<=n;i++){
        int mind=INT_MAX,temp=-1;
        for(int j=1;j<=n;j++){
            if(vd[j]==0&&mindist[j]<mind){
                mind=mindist[j];
                temp=j;
                
            }
        }
        if(temp==-1){
            return 0;
        }
        vd[temp]=1;
        for(int j=1;j<=n;j++){
            if(vd[j]==0&&g[temp][j]>0){
                if(mindist[j]>g[temp][j]){
                    mindist[j]=g[temp][j];
                    path[j]=temp;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vd[i]==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int g[105][105]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                g[i][j]=0;
            }else{
                g[i][j]=INT_MAX;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int num,t;
            scanf("%d%d",&num,&t);
            g[i][num]=t;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][k]!=INT_MAX&&g[k][j]!=INT_MAX){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    }
    int ret=INT_MAX,mark=-1;
    for(int i=1;i<=n;i++){
        int maxd=0,flag=1;
        for(int j=1;j<=n;j++){
            if(g[i][j]==INT_MAX){
                flag=0;
                break;
            }
            if(g[i][j]>maxd){
                maxd=g[i][j];
            }
        }
        if(flag&&maxd<ret){
            ret=maxd;
            mark=i;
        }
    }
    if(mark==-1){
        printf("disjoint");
        return 0;
    }
    printf("%d %d",mark,ret);
    return 0;
}