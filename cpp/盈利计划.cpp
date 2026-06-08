#include<bits/stdc++.h>
using namespace std;

long long ret=0;
vector<int> profit;
    vector<int> group;
void dfs(int people,int pro,int x){
    if(x==profit.size()){
        if(pro<=0){
            ret++;
        }
        return;
        
    }
        dfs(people,pro,x+1);
        if(group[x]<=people){
            dfs(people-group[x],pro-profit[x],x+1);
        }
    
}
int main(){
    string s;
    getline(cin,s);
    int n,minprofit;
    string temp;
    int i;
    for(i=4;s[i]!=',';i++){
        temp+=s[i];
    }
    n=stoi(temp);
    temp.clear();
    for(i=i+13;s[i]!=',';i++){
        temp+=s[i];
    }
    minprofit=stoi(temp);
    temp.clear();
    for(i=i+9;s[i]!=']';i++){
        if(s[i]=='['||s[i]==']') continue;
        if(s[i]==','){
            group.push_back(stoi(temp));
            temp.clear();
            continue;
        }
        temp+=s[i];
    }
    if(!temp.empty()) group.push_back(stoi(temp));
    temp.clear();
    for(i=i+11;s[i]!=']';i++){
        if(s[i]=='['||s[i]==']') continue;
        if(s[i]==','){
            profit.push_back(stoi(temp));
            temp.clear();
            continue;
        }
        temp+=s[i];
    }
    if(!temp.empty()) profit.push_back(stoi(temp));
    dfs(n,minprofit,0);
    int ans=ret%1000000007;
    cout<<ans;
    return 0;
}