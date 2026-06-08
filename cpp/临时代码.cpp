#include <bits/stdc++.h>
using namespace std;

struct tree {
    int val;
    tree* left;
    tree* right;
    tree(int x):val(x),left(NULL),right(NULL){}
};

vector<int> preorder, inorder;
unordered_map<int,int> pos;

tree* buildtree(int prel,int prer,int inl,int inr){
    if(prel > prer) return NULL;

    int rootVal = preorder[prel];
    tree* root = new tree(rootVal);

    int i = pos[rootVal];
    int leftsize = i - inl;

    root->left  = buildtree(prel+1, prel+leftsize, inl, i-1);
    root->right = buildtree(prel+leftsize+1, prer, i+1, inr);

    return root;
}

void bfs(tree* root){
    queue<tree*> q;
    q.push(root);

    vector<int> ret;

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

    while(!ret.empty() && ret.back() == -1) ret.pop_back();

    cout << '[';
    for(int i=0;i<ret.size();i++){
        if(i) cout << ',';
        if(ret[i]==-1) cout << "null";
        else cout << ret[i];
    }
    cout << ']' << endl;
}

int main(){
    int n;
    cin >> n;

    preorder.resize(n);
    inorder.resize(n);

    for(int i=0;i<n;i++) cin >> preorder[i];
    for(int i=0;i<n;i++){
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }

    tree* root = buildtree(0,n-1,0,n-1);
    bfs(root);

    return 0;
}