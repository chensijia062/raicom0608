#include<bits/stdc++.h>
using namespace std;

struct LinkNode{
    int val;
    LinkNode* next;
};
void insertpost(LinkNode* head,int num){
    LinkNode* p=new LinkNode;
    LinkNode* q=head;
    p->val=num;
    p->next=NULL;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;
    return;
}
void deleteelement(LinkNode* head,int maxx){
    LinkNode* p=head->next;
    LinkNode* q=head;
    LinkNode* k=q;
    while(p!=NULL){
        if(p->val==maxx){
            k=q;
            p=p->next;
            q=q->next;
        }else{
            p=p->next;
            q=q->next;
        }
        
    }
    k->next=k->next->next;
    return;
}
int main()
{
    int x;
    cin>>x;
    int maxx=-1;
    LinkNode* head=new LinkNode;
    head->next=NULL;
    for(int i=0;i<x;i++){
        int num;
        cin>>num;
        maxx=max(maxx,num);
        insertpost(head,num);
    }
    deleteelement(head,maxx);
    insertpost(head,maxx);
    LinkNode* p=head->next;
    while(p!=NULL){
        cout<<p->val<<endl;
        p=p->next;
    }
    return 0;
}