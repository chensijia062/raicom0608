#include<stdio.h>
#include<string.h>

char word[5005][15];
    int vd[5005];
int judge(char a[],char b[]){
    int cnt=0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    return cnt==1;
}
int main()
{
    char beginword[15],endword[15];
    scanf("%s%s",beginword,endword);
    int n;
    scanf("%d",&n);
    int wordsize=1;
    strcpy(word[wordsize++],beginword);

    for(int i=0;i<n;i++){
        scanf("%s",word[wordsize++]);
    }
   
    int cnt=0,queue[5005];
    int front=0,rear=0;
    queue[rear++]=1;
    vd[1]=1;
    while(front<rear){
        cnt++;
        int f=front,r=rear;
        for(int i=0;i<r-f;i++){
            int temp=queue[front++];
            for(int j=1;j<wordsize;j++){
                if(vd[j]==0&&judge(word[temp],word[j])){
                    if(strcmp(word[j],endword)==0){
                        printf("%d",cnt+1);
                        return 0;
                    }
                    queue[rear++]=j;
                    vd[j]=1;
                }
            }
        }
    }
    printf("0");
    return 0;
}
