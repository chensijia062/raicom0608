#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > p;
int dv[100005]={0},bv[100005]={0};
vector<int> e[100005];
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }else{
        return a.first<b.first;
    }
}
void dfs(int x){
    cout<<x<<" ";
    dv[x]++;
    for(int i=0;i<e[x].size();i++){
        if(dv[e[x][i]]==0){
            dfs(dv[e[x][i]]);
        }
    }
    return;
}
void bfs(int x){
    queue<int> q;
    q.push(x);
    
    while(q.size()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        bv[temp]++;
        for(int i=0;i<e[temp].size();i++){
            if(bv[e[temp][i]]==0){
                q.push(e[temp][i]);
            }
        }
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<m;i++){
        e[p[i].first].push_back(p[i].second);
    }
    dfs(1);
    cout<<endl;
    bfs(1);
    return 0;
}