#include<bits/stdc++.h>
using namespace std;

struct tree{
    char val;
    tree* left,*right;
};
struct Listnode{
    char val;
    Listnode* pre;
    Listnode* next;
};
Listnode* head=new Listnode;
Listnode* cur=head;
void mid(tree* root){
    if(root==NULL){
        return;
    }else{
        mid(root->left);
        Listnode* temp=new Listnode;
        temp->val=root->val;
        cur->next=temp;
        cur=temp;
        mid(root->right);
        return;
    }
}
int main()
{
    char x;
    vector<char> q;
    while(cin.peek()!='\n'&&cin>>x){
        q.push_back(x);
    }
    if(q.empty()||q[0]=='#'){
        return 0;
    }
    queue<tree*> t;
    tree* root=new tree;
    root->val=q[0];
    t.push(root);
    int i=1;
    while(t.size()&&i<q.size()){
        tree* cur=t.front();
        t.pop();
        if(i<q.size()&&q[i]!='#'){
            cur->left=new tree;
            cur->left->val=q[i];
            cur->left->left=cur->left->right=NULL;
            t.push(cur->left);
        }else if(i<q.size()&&q[i]=='#'){
            cur->left=NULL;
        }
        i++;
        if(i<q.size()&&q[i]!='#'){
            cur->right=new tree;
            cur->right->val=q[i];
            cur->right->left=cur->right->right=NULL;
            t.push(cur->right);
        }else if(i<q.size()&&q[i]=='#'){
            cur->right=NULL;
        }
        i++;
    }
    mid(root);
    cur->next=head->next;
    cur=head->next;
    Listnode* pr=cur;
    while(cur->next!=head->next){
        cur=cur->next;
        cur->pre=pr;
        pr=pr->next;
    }
    head->next->pre=pr;
    cur=head->next;
    if(cur==NULL){
        return 0;
    }
    cout<<cur->val;
    cur=cur->next;
    while(cur!=head->next){
        cout<<" <-> "<<cur->val;
        cur=cur->next;
    }
    return 0;
}