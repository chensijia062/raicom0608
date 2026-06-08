#include<bits/stdc++.h>
using namespace std;

vector<string> ret;
vector<string> v;
int mark;
void dfs(int target,int dis,int from){
    if(dis==0){
        ret.push_back(v[target]);
        return;
    }
    if(target*2<v.size()&&v[target*2]!="#"&&target*2!=from){
        dfs(target*2,dis-1,target);
        
    }
    
    if(target*2+1<v.size()&&v[target*2+1]!="#"&&target*2+1!=from){
        dfs(target*2+1,dis-1,target);
        
    }
    if(target/2>0&&v[target/2]!="#"&&target/2!=from){
        dfs(target/2,dis-1,target);
        
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    string s;
    cin>>s;
    
    v.push_back("0");
    string temp;
    for(int i=0;i<s.length();i++){
        
        if(s[i]=='['||s[i]==']'){
            continue;
        }
        if(s[i]==','){
            v.push_back(temp);
            temp.clear();
            continue;
        }
        temp+=s[i];
    }
    if(!temp.empty()) v.push_back(temp);
    string target;
    int dis;
    cin>>target>>dis;
    for(int i=1;i<v.size();i++){
        if(v[i]==target){
            mark=i;
            break;
        }
    }
    dfs(mark, dis,-1);
    
    cout<<"[";
    for(int i=0;i<ret.size();i++){
        if(i==0){
            cout<<ret[i];
        }else{
            cout<<","<<ret[i];
        }
    }
    cout<<"]";
    return 0;
}