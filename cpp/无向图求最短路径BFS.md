//无向图求最短路径 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> edge[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int s,t;
    cin>>s>>t;
    queue<int> q;
    vector<int> dist(n+1,INT_MAX);
    dist[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i=0;i<edge[temp].size();i++)
        {
            if(dist[edge[temp][i]]==INT_MAX)
            {
                dist[edge[temp][i]]=dist[temp]+1;
                q.push(edge[temp][i]);
            }
        }
    }
    if(dist[t]==INT_MAX){
    	cout<<-1;
	}else{
	
    cout<<dist[t];
    }
    return 0;
}