#include<bits/stdc++.h>
using namespace std;

struct Listnode{
    int val;
    Listnode* next;
};
void insertpost(Listnode* &head,int num){
    Listnode* p=new Listnode;
    Listnode* q=head;
    p->val=num;
    p->next=NULL;
    if(head==NULL){
        head=p;
        return;
    }
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;
    return;
}
void reverse(Listnode* head){
    if(head->next==NULL){
        cout<<head->val<<" ";
        return;
    }else{
        reverse(head->next);
        cout<<head->val<<" ";
        return;
        }
}
bool judge(Listnode* head){
    if(head->next==NULL){
        return true;
    }else if(head->val<=head->next->val){
        return judge(head->next);
    }else{
        return false;
    }
}
int main()
{
    Listnode* head=NULL;
    int x;
    while(cin>>x){
        if(x==-1){
            break;
        }else{
            insertpost(head,x);
        }
    }
    reverse(head);
    cout<<endl;
    if(judge(head)){
        cout<<"is AscendOrder";
    }else{
        cout<<"not AscendOrder";
    }
    return 0;
}