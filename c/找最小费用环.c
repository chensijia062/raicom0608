#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min(int x,int y){
    return x<y?x:y;
}

int n,m;
int vd[105]={0};
int mincost(int g[][105],int start,int end){
    for(int i=0;i<=n;i++){
        vd[i]=0;
    }
    int mindist[105];
    for(int i=1;i<=n;i++){
        mindist[i]=INT_MAX;
    }
    int vd[105]={0};
    mindist[start]=0;
    for(int j=1;j<=n;j++){
    int mind=INT_MAX,temp=-1;
    for(int i=1;i<=n;i++){
        if(vd[i]==0&&mindist[i]<mind){
            mind=mindist[i];
            temp=i;
        }

    }
    if(temp==-1) break;
    vd[temp]=1;
    for(int i=1;i<=n;i++){
        if(vd[i]==0&&g[temp][i]>0){
            mindist[i]=min(mindist[i],mindist[temp]+g[temp][i]);
        }
    }
}
return mindist[end];
}
int main()
{
    freopen("in.txt","r",stdin);
    int g[105][105]={0};
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(g[a][b]==0||g[a][b]>c){
            g[a][b]=g[b][a]=c;
        }
    }
    int ret=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]){
                int temp=g[i][j];
                g[i][j]=g[j][i]=0;
                if(mincost(g,i,j)==INT_MAX){
                    g[i][j]=g[j][i]=temp;
                    continue;
                }
                ret=min(ret,mincost(g,i,j)+temp);
                g[i][j]=g[j][i]=temp;
            }
        }
    }
    if(ret==INT_MAX){
        printf("It's impossible.");
    }else{
        printf("%d",ret);
    }
    return 0;
}