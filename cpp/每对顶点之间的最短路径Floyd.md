int g[105][105]={0},path[105][105];
for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
        path[i][j]=-1;
    }
}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                g[i][j]=0;
            }else{
                g[i][j]=INT_MAX;
            }
        }
    }
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=z;
        path[x][y]=x;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][k]!=INT_MAX&&g[k][j]!=INT_MAX){
                    if(g[i][k]+g[k][j]<g[i][j]){
                        g[i][j]=g[i][k]+g[k][j];
                        path[i][j]=path[k][j];
                    }
                }
            }
        }
    }
    vector<int> ret,temp,i,j;
    for(int i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(g[i][j]!=INT_MAX&&i!=j){
                temp=path[i][j];
                ret.push_back(j);
                while(temp!=i){
                    ret.push_back(temp);
                    temp=path[temp][j];
                }
                ret.push_back(i);
                for(int k=ret.size()-1;k>=0;k--){
                    cout<<ret[k];
                }
            }
        }
    }