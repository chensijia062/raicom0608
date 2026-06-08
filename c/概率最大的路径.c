#include<stdio.h>
#include<stdlib.h>

struct edge{
    int a,b;
};
double max(double a,double b){
    return a>b?a:b;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    double g[n][n];
    struct edge e[m];
    int esize=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        e[esize].a=a;
        e[esize].b=b;
        esize++;
    }
    for(int i=0;i<esize;i++){
        double succprob;
        scanf("%lf",&succprob);
        g[e[i].a][e[i].b]=g[e[i].b][e[i].a]=succprob;
    }
    int start,end;
    
    scanf("%d%d",&start,&end);
    int vd[10005]={0};
    double mindist[10005]={0};
    mindist[start]=1;
    for(int i=1;i<=n;i++){
        double maxp=0;
        int temp;
        for(int j=0;j<n;j++){
            if(vd[j]==0&&mindist[j]>maxp){
                maxp=mindist[j];
                temp=j;
            }
        }
        vd[temp]=1;
       
        for(int j=0;j<n;j++){
            if(vd[j]==0&&g[temp][j]){
                mindist[j]=max(mindist[j],mindist[temp]*g[temp][j]);
            }
        }
    }
    printf("%10g",mindist[end]);
    return 0;
}