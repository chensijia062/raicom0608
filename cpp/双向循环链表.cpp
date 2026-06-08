#include<bits/stdc++.h>
using namespace std;

struct dnode{
    int val;
    dnode* prior;
    dnode* next;
};
void printnode(dnode* head){
    dnode* p=head->next;
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    return;
}
void insert(dnode* head,int i,int e){
    dnode* p=head->next;
    dnode* pr=head;
    dnode* q=new dnode;
    q->val=e;
    i--;
    while(i){
        if(p==NULL){
            return;
        }
        p=p->next;
        pr=pr->next;
        i--;
    }
    q->next=pr->next;
    pr->next=q;
    if(p!=NULL){
        p->prior=q;
    }
    q->prior=pr;
    return;
}
void deleteelement(dnode* head,int i){
    dnode* p=head->next;
    dnode* pr=head;
    i--;
    while(i){
        if(p==NULL){
            return;
        }
        p=p->next;
        pr=pr->next;
        i--;
    }
    if(p==NULL){
        return;
    }
    pr->next=p->next;
    if(p->next!=NULL){
        p->next->prior=pr;
    }
    delete p;
    return;
}

int main()
{
    dnode* head=new dnode;
    head->next=NULL;
    int num,i,e;
    while(cin>>num){
        if(num==0){
            printnode(head);
        }else if(num==1){
            cin>>i>>e;
            insert(head,i,e);
        }else if(num==2){
            cin>>i;
            deleteelement(head,i);
        }
    }
    return 0;
}