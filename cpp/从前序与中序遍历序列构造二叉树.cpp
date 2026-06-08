#include<bits/stdc++.h>
using namespace std;

struct tree {
    int val;
    tree* left=NULL;
    tree* right=NULL;
};
vector<int> preorder;
    vector<int> inorder;
tree* buildtree(int prel,int prer,int inl,int inr){
    if(prel>prer||inl>inr){
        return NULL;
    }
    tree* root=new tree;
    root->val=preorder[prel];
    int i;
    for(i=inl;inorder[i]!=root->val;i++);
    int leftsize=i-inl;
    root->left=buildtree(prel+1,prel+leftsize,inl,i-1);
    root->right=buildtree(prel+leftsize+1,prer,i+1,inr);
    return root;
}
vector<int> ret;
void bfs(tree* root){
    if(root==NULL){
        return;
    }
    queue<tree*> q;
    q.push(root);
    while(!q.empty()){
        tree* cur = q.front(); q.pop();
        if(cur){
            ret.push_back(cur->val);
            q.push(cur->left);
            q.push(cur->right);
        }else{
            ret.push_back(-1);
        }
    }
    while(ret.size()&&ret.back()==-1){
        ret.pop_back();
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        preorder.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        inorder.push_back(x);
    }
    tree* root=buildtree(0,n-1,0,n-1);
    bfs(root);
    cout<<'[';
    for(int i=0;i<ret.size();i++){
        if(i==0){
            if(ret[i]==-1){
                cout<<"null";
            }else{
                cout<<ret[i];
            }
        }
        else{
            if(ret[i]==-1){
                cout<<",null";
            }else{
                cout<<","<<ret[i];
            }
        }

    }
    cout<<']';
    return 0;
}