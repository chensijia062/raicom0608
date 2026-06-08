#include<bits/stdc++.h>
using namespace std;

struct tree{
    string val;
    tree* left;
    tree* right;
};
vector<string> ret;
void pre(tree* root){
    if(root==NULL){
        
        return;
    }else{
        ret.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
}
int main()
{
    tree* root=new tree;
    root->left=root->right=NULL;
    string s;
    cin>>s;
    vector<string> v;
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
    queue<tree*> q;
    root->val=v[0];
    q.push(root);
    int i=1;
    while(q.size()&&i<v.size()){
        tree* cur=q.front();
        q.pop();
        if(i<v.size()&&v[i]!="null"){
            cur->left=new tree;
            cur->left->val=v[i];
            cur->left->left=cur->left->right=NULL;
            q.push(cur->left);
        }else if(i<v.size()&&v[i]=="null"){
            cur->left=NULL;
        }
        i++;
        if(i<v.size()&&v[i]!="null"){
            cur->right=new tree;
            cur->right->val=v[i];
            cur->right->left=cur->right->right=NULL;
            q.push(cur->right);
        }else if(i<v.size()&&v[i]=="null"){
            cur->right=NULL;
        }
        i++;
    }
    cout<<'[';
    pre(root);
    for(int i=0;i<ret.size();i++){
        if(i==0){
            cout<<ret[i];
        }else{
            cout<<",null,"<<ret[i];
        }
    }
    cout<<"]";
    return 0;
}