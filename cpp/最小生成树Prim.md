最小生成树Prim:
int main()
{
    int n,count;
    cin>>n>>count;
    int g[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            g[i][j]=-1;
        }
    }
    for(int i=0;i<count;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=g[y][x]=z;
    }
    int mindist[10005];
    for(int i=0;i<=n;i++){
        mindist[i]=INT_MAX;
    }
    int vd[10005]={0};
    mindist[1]=0;
    int ret=0;
    for(int i=1;i<=n;i++){
        int minv=INT_MAX,temp=0;
        for(int j=1;j<=n;j++){
            if(vd[j]==0&&mindist[j]<minv){
                minv=mindist[j];
                temp=j;
            }
 
        }
        vd[temp]=1;
            for(int j=1;j<=n;j++){
                if(vd[j]==0&&g[temp][j]!=-1){
                    mindist[j]=min(mindist[j],g[temp][j]);
                }
            }
 
    }
    for(int i=2;i<=n;i++){
        ret+=mindist[i];
    }
    cout<<ret;
    return 0;
}