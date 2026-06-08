#include<bits/stdc++.h>
using namespace std;

struct tree {
    int val;
    tree* left=NULL;
    tree* right=NULL;
};
vector<int> nums;
tree* maxtree(int left,int right){
    if(left>right){
        return NULL;
    }
    int maxval=-1;
    int temp;
    for(int i=left;i<=right;i++){
        if(nums[i]>maxval){
            maxval=nums[i];
            temp=i;
        }
    }
    tree* root=new tree;
    root->val=maxval;
    root->left=maxtree(left,temp-1);
    root->right=maxtree(temp+1,right);
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
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    tree* root=maxtree(0,n-1);
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