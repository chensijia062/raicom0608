#include<stdio.h>
#include<stdlib.h>

struct Listnode{
    int val;
    struct Listnode* next;
};

int num;

void insertpost(struct Listnode** head,int num){

    struct Listnode* p=(struct Listnode*)malloc(sizeof(struct Listnode));

    struct Listnode* q=*head;

    p->val=num;

    p->next=NULL;

    if(*head==NULL){

        *head=p;

        return;
    }

    while(q->next!=NULL){

        q=q->next;
    }

    q->next=p;

    return;
}

void reverse(struct Listnode* head){

    if(head->next==NULL){

        printf("%d ",head->val);

        return;

    }else{

        reverse(head->next);

        printf("%d ",head->val);

        return;
    }
}

struct Listnode* deleteelement(struct Listnode* head,int num){

    if(head==NULL){

        return NULL;

    }else if(head->val==num){

        struct Listnode* p=deleteelement(head->next,num);

        free(head);

        return p;

    }else{

        head->next=deleteelement(head->next,num);

        return head;
    }
}

int main()
{
    struct Listnode* head=NULL;

    int x;

    while(scanf("%d",&x)!=EOF){

        if(x==9999){

            break;

        }else{

            insertpost(&head,x);
        }
    }

    scanf("%d",&num);

    head=deleteelement(head,num);

    reverse(head);

    return 0;
}