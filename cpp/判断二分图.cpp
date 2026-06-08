#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> g[n];
    for(int i=0;i<n;i++){
        int cnt;
        cin>>cnt;
        for(int j=0;j<cnt;j++){
            int x;
            cin>>x;
            g[i].push_back(x);
        }
    }
    int color[n]={0};
    color[0]=1;
    bool ret=true;
    queue<int> q;
    q.push(0);
    while(q.size()){
        int temp=q.front();
        q.pop();
        for(int i=0;i<g[temp].size();i++){
            if(color[g[temp][i]]==color[temp]){
                ret=false;
            }else if(color[g[temp][i]]==0){
                color[g[temp][i]]=-color[temp];
                q.push(g[temp][i]);
            }
        }
    }
    if(ret){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}