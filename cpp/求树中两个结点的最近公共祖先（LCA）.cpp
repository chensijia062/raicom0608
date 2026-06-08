#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    int parent[10005]={0};
    int vd[10005]={0};
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        parent[y]=x;
    }
    int u,v;
    cin>>u>>v;
    while(u){
        vd[u]=1;
        u=parent[u];
    }
    while(v){
        if(vd[v]){
            cout<<v;
            break;
        }else{
            v=parent[v];
        }
    }
    return 0;
}