#include<bits/stdc++.h>
using namespace std;

struct Listnode{
    int val;
    Listnode* next=NULL;
};
void insertpost(Listnode* &head,int num){
    Listnode* p=new Listnode;
    p->val=num;
    if(head==NULL){
        head=p;
    }else{
        Listnode* pr=head;
        while(pr->next!=NULL){
            pr=pr->next;
        }
        pr->next=p;
    }
    return;
}
Listnode* mid(Listnode* head){
    Listnode* p=head->next;
    Listnode* pr=head;
    while(p&&p->next){
        p=p->next->next;
        pr=pr->next;
    }
    return pr;
}
Listnode* merge(Listnode* l1,Listnode* l2){
    Listnode* head=NULL;
    if(l1==NULL){
        return l2;
    }else if(l2==NULL){
        return l1;
    }
    if(l1->val<l2->val){
        head=l1;
        l1=l1->next;
    }else{
        head=l2;
        l2=l2->next;
    }
    Listnode* p=head;
    while(l1&&l2){
        if(l1->val<l2->val){
            p->next=l1;
            l1=l1->next;
        }else{
            p->next=l2;
            l2=l2->next;
        }
        p=p->next;
    }
    if(l1){
        p->next=l1;
    }else if(l2){
        p->next=l2;
    }
    return head;
}
Listnode* sortlist(Listnode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Listnode* midlist=mid(head);
    Listnode* right=midlist->next;
    midlist->next=NULL;
    Listnode* left=sortlist(head);
    right=sortlist(right);
    return merge(left,right);
}
int main()
{
    int n;
    cin>>n;
    Listnode* head=NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertpost(head,x);
    }
    Listnode* ret=sortlist(head);
    Listnode* cur=ret;
    while(cur){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
    return 0;
}