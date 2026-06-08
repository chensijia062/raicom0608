#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree{
    char val[1005];
    struct tree* left;
    struct tree* right;
};
int ret[105][505],path[505];

int x=0,pathsize=0,retsize=0;
void dfs(int sum,struct tree* root){
    if(root==NULL){
        return;
    }
    x+=atoi(root->val);
    path[pathsize++]=atoi(root->val);
    
    if(root->left==NULL&&root->right==NULL){
        if(x==sum){
            for(int i=0;i<pathsize;i++){
                ret[retsize][i]=path[i];
            }
            retsize++;
        }
        
    }else{
        dfs(sum,root->left);
        dfs(sum,root->right);
    }
    pathsize--;
    x-=atoi(root->val);
    
    }


int main()
{
	for(int i=0;i<105;i++){
	for(int j=0;j<505;j++){
		ret[i][j]=1002;
	}
}
    char s[10005];
    fgets(s,sizeof(s),stdin);
    s[strlen(s)-1]='\0';
    int slen=strlen(s);
    int sum;
    scanf("%d",&sum);
    char temp[10005];
    temp[0]='\0';
    char v[105][505];
    int vsize=0;
    for(int i=7;i<slen;i++){
        if(s[i]=='['||s[i]==']'){
            continue;
        }else if(s[i]==','){
            strcpy(v[vsize++],temp);
            temp[0]='\0';
            continue;
        }
        int len=strlen(temp);
        temp[len]=s[i];
        temp[len+1]='\0';
    }
    if(strlen(temp)){
        strcpy(v[vsize++],temp);
    }
    if(vsize==0){
        printf("[]");
        return 0;
    }
    struct tree* t[105];    
    int front=0,rear=0;
    struct tree* root=(struct tree*)malloc(sizeof(struct tree));
    strcpy(root->val,v[0]);
    root->left=root->right=NULL;
    t[rear++]=root;
    int i=1;
    while(front<rear&&i<vsize){
        struct tree* cur=t[front++];
        if(i<vsize&&strcmp(v[i],"null")!=0){
            cur->left=(struct tree*)malloc(sizeof(struct tree));
            strcpy(cur->left->val,v[i]);
            cur->left->left=cur->left->right=NULL;
            t[rear++]=cur->left;
        }else if(i<vsize&&strcmp(v[i],"null")==0){
            cur->left=NULL;
        }
        i++;
        if(i<vsize&&strcmp(v[i],"null")!=0){
            cur->right=(struct tree*)malloc(sizeof(struct tree));
            strcpy(cur->right->val,v[i]);
            cur->right->left=cur->right->right=NULL;
            t[rear++]=cur->right;
        }else if(i<vsize&&strcmp(v[i],"null")==0){
            cur->right=NULL;
        }
        i++;
    }
    dfs(sum,root);
    printf("[");
    for(int i=0;i<retsize;i++){
        if(i==0){
        for(int j=0;ret[i][j]!=1002;j++){
            if(j==0){
                printf("[%d",ret[i][j]);
            }else{
                printf(",%d",ret[i][j]);
            }
        }
        printf("]");
    }else{
        printf(",");
        for(int j=0;ret[i][j]!=1002;j++){
            if(j==0){
                printf("[%d",ret[i][j]);
            }else{
                printf(",%d",ret[i][j]);
            }
        }
        printf("]");
    }
    }
    printf("]");
    return 0;
}