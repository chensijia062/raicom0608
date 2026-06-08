int main()
{
    int n,m;
    int vd[105]={0},path[105];
    for(int i=0;i<=n;i++){
        path[i]=-1;
    }
    int mindist[105];
    for(int i=1;i<=n;i++){
        mindist[i]=INT_MAX;
    }

    int g[105][105]={0};
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=c;
        path[b]=a;
    }
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
            if(mindist[temp]+g[temp][i]<mindist[i]){
                mindist[i]=mindist[temp]+g[temp][i];
                path[i]=temp;
            }
        }
    }
}
    vector<int> ret,cur;
    for(int i=1;i<=n;i++){
        if(vd[i]&&i!=start){
            ret.push_back(i);
            cur=path[i];
            if(cur==-1){
                printf("no");
            }else{
                while(cur!=start){
                    ret.push_back(cur);
                    cur=path[cur];

                }
            }
            ret.push_back(start);
            for(int j=ret.size()-1;j>=0;j--){
                cout<<ret[j];
            }
        }
        ret.clear();
    }
}