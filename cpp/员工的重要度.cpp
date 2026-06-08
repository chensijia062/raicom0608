#include<bits/stdc++.h>
using namespace std;

struct worker{
    int id,importance;
    vector<int> subordinates;
};
int target;
vector<int> w[10005];
int find(int x){
    int m;
for(int i=0;;i++){
    if(w[i][0]==x){
        m=i;
        break;
    }
}
return m;
}
int main()
{
    string s;
    
    int mark;
    stack<char> st;
    string temp;
    temp.clear();
    int index=-1;
    getline(cin,s);
    s.erase(12,1);
    s.erase(s.end()-9);
    
    for(int i=12;i<s.length();i++){
         if(s[i]=='['){
            if(st.empty()){
                index++;
            }
            st.push(s[i]);
            continue;
        }else if(s[i]==','){
            if(!temp.empty()){
            w[index].push_back(stoi(temp));
            temp.clear();
            continue;
        }
        
    }else if(s[i]==']'&&st.size()>0&&st.top()=='['){
        st.pop();
    }else if(s[i]=='i'){
        mark=i+5;
        break;
    }else{
        temp+=s[i];
    }
    
}
temp.clear();
for(int i=mark;i<s.length();i++){
    temp+=s[i];
}
int x=stoi(temp);
int ret=0;
for(int i=0;;i++){
    if(w[i][0]==x){
        target=i;
        break;
    }
}
ret+=w[target][1];

for(int i=2;i<w[target].size();i++){
    int y=find(w[target][i]);
    ret+=w[y][1];
}
cout<<ret;
return 0;
}