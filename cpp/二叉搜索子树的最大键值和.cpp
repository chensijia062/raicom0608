#include<bits/stdc++.h>
using namespace std;

struct tree {
    int val;
    tree* left;
    tree* right;
};
tree* temp;
int ret=0,x=0;
bool judge(tree* root, int minv, int maxv){
    if(root == NULL) return true;

    if(root->val <= minv || root->val >= maxv){
        return false;
    }

    return judge(root->left, minv, root->val) &&
           judge(root->right, root->val, maxv);
}
void pre(tree* root){
    if(root==NULL){
        return;
    }
    x+=root->val;
    pre(root->left);
    pre(root->right);
}
void find(tree* root){
    if(root==NULL){
        return;
    }
    if(judge(root,INT_MIN, INT_MAX)){
        x=0;
        pre(root);
        ret=max(ret,x);
    }
        find(root->left);
        find(root->right);
        
}
int main()
{
    string s;
    getline(cin,s);
    string temp;
    queue<tree*> q;
    vector<string> v;
    for(int i=7;i<s.length();i++){
        if(s[i]=='['||s[i]==']'){
            continue;
        }else if(s[i]==','){
            
            v.push_back(temp);
            temp.clear();
            continue;
        }
        temp+=s[i];
    }
    if(temp.length()){
        v.push_back(temp);
    }
    tree* root=new tree;
    int x=stoi(v[0]);
    root->val=x;
    q.push(root);
    int i=1;
    while(q.size()&&i<v.size()){
        tree* cur=q.front();
        q.pop();
        if(i<v.size()&&v[i]!="null"){
            cur->left=new tree;
            cur->left->val=stoi(v[i]);
            cur->left->left=cur->left->right=NULL;
            q.push(cur->left);
        }else{
            cur->left=NULL;
        }
        i++;
        if(i<v.size()&&v[i]!="null"){
            cur->right=new tree;
            cur->right->val=stoi(v[i]);
            cur->right->left=cur->right->right=NULL;
            q.push(cur->right);
        }else{
            cur->right=NULL;
        }
        i++;
    }
    find(root);
    cout<<ret;
    return 0;
}