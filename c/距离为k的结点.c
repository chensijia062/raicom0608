#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char ret[10005][100];

int retsize=0;

char v[10005][100];

int vsize=0;

int mark;

void dfs(int target,int dis,int from){

    if(dis==0){

        strcpy(ret[retsize++],v[target]);

        return;
    }

    if(target*2<vsize &&
       strcmp(v[target*2],"null")!=0 &&
       target*2!=from){

        dfs(target*2,dis-1,target);
    }

    if(target*2+1<vsize &&
       strcmp(v[target*2+1],"null")!=0 &&
       target*2+1!=from){

        dfs(target*2+1,dis-1,target);
    }

    if(target/2>0 &&
       strcmp(v[target/2],"null")!=0 &&
       target/2!=from){

        dfs(target/2,dis-1,target);
    }
}
int cmp(const void* a,const void* b){
    char* x=(char*)a;
    char* y=(char*)b;
    return (strcmp(x,y));
}
int main()
{
    
    char s[10005];

    scanf("%s",s);

    strcpy(v[vsize++],"0");

    char temp[100];

    temp[0]='\0';

    for(int i=0;i<strlen(s);i++){

        if(s[i]=='[' || s[i]==']'){

            continue;
        }

        if(s[i]==','){

            strcpy(v[vsize++],temp);

            temp[0]='\0';

            continue;
        }

        int len=strlen(temp);

        temp[len]=s[i];

        temp[len+1]='\0';
    }

    if(strlen(temp)>0){

        strcpy(v[vsize++],temp);
    }

    char target[100];

    int dis;

    scanf("%s%d",target,&dis);

    for(int i=1;i<vsize;i++){

        if(strcmp(v[i],target)==0){

            mark=i;

            break;
        }
    }

    dfs(mark,dis,-1);
    qsort(ret,retsize,sizeof(ret[0]),cmp);

    printf("[");

    for(int i=0;i<retsize;i++){

        if(i==0){

            printf("%s",ret[i]);

        }else{

            printf(",%s",ret[i]);
        }
    }

    printf("]");

    return 0;
}
