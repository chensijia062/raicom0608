#include<bits/stdc++.h>
using namespace std;

struct Node{
    int col, row;
    string val;
};
bool cmp(Node a, Node b){
    if(a.col != b.col) return a.col < b.col;
    if(a.row != b.row) return a.row < b.row;
    return a.val < b.val;
}
int main()
{
    string s;
    getline(cin,s);
    vector<string> v;
    v.push_back("0"); 
    string temp;
    for(int i=0;i<s.length();i++){
        if(s[i]=='['||s[i]==']'||s[i]=='r'||s[i]=='o'||s[i]=='t'||s[i]=='='||s[i]==' ') continue;
        if(s[i]==','){
            v.push_back(temp);
            temp.clear();
            continue;
        }
        temp+=s[i];
    }
    if(!temp.empty()) v.push_back(temp);
    if(v.size() <= 1){
        cout<<"[]";
        return 0;
    }
    vector<Node> ret(v.size(), {0,0,""});
    ret[1] = {0, 0, v[1]};
    for(int i=1;i<v.size();i++){
        if(v[i]=="null") continue;
        if(i*2 < v.size() && v[i*2]!="null"){
            ret[i*2] = {ret[i].col-1, ret[i].row+1, v[i*2]};
        }
        if(i*2+1 < v.size() && v[i*2+1]!="null"){
            ret[i*2+1] = {ret[i].col+1, ret[i].row+1, v[i*2+1]};
        }
    }
    vector<Node> nodes;
    for(int i=1;i<v.size();i++){
        if(v[i]!="null"){
            nodes.push_back(ret[i]);
        }
    }
    sort(nodes.begin(), nodes.end(), cmp);
    if(nodes.size() <= 1){
    return 0; 
}
    cout << "[";
    for(int i=0;i<nodes.size();){
        cout << "[";
        int j = i;
        while(j<nodes.size() && nodes[j].col == nodes[i].col){
            if(j>i) cout << ",";
            cout << nodes[j].val;
            j++;
        }
        cout << "]";
        if(j<nodes.size()) cout << ",";
        i = j;
    }
    cout << "]";
    return 0;
}