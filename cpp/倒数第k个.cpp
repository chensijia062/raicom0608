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
int main()
{
    int k,x,cnt=0;
    cin>>k;
    LinkNode* head=new LinkNode;
    head->next=NULL;
    while(cin.peek()!='\n'&&cin>>x){
        insertpost(head,x);
        cnt++;
    }
    if(k>cnt){
        cout<<"Not Found";
    }else{
        k=cnt-k;
    }
    LinkNode* p=head->next;
    while(k--){
        p=p->next;
        
    }
    cout<<p->val;
    return 0;
}