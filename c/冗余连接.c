#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int fa[1005];
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        return fa[x]=find(fa[x]);
    }
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy){
        return;
    }else{
        fa[fy]=fx;
        return;
    }
}
int main()
{
    char s[10005];
    int ssize=0;
    fgets(s,10005,stdin);
    
    s[strlen(s)-1]='\0';
    ssize=strlen(s);
    for(int i=0;i<=ssize;i++){
        fa[i]=i;
    }
    char temp[10005];
    temp[0]='\0';
    char v[1005][1005];
    int vsize=0;
    for(int i=1;i<=ssize-2;i++){
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
    int a,b;
    for(int i=0;i<vsize-1;i+=2){
        int x=atoi(v[i]),y=atoi(v[i+1]);
        int fx=find(x),fy=find(y);
        if(fx==fy){
            a=x;
            b=y;
        }else{
            merge(x,y);
        }
    }
    printf("[%d,%d]",a,b);
    return 0;
}
