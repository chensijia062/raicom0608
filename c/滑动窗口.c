#include<stdio.h>

int main()
{
    
    int num[10001];
    char ch;
    int s,i=0;
    while(scanf("%d%c",&num[i],&ch)==2){
        i++;
        if(ch=='\n'){
            break;
        }
        
    }
    int minlen=i;
    scanf("%d",&s);
    int left=0,right=0,sum=0;
    for(right=0;right<i;right++){
        sum+=num[right];
        while(sum>=s){
            int len=right-left+1;
            minlen=minlen<len?minlen:len;
            sum-=num[left++];
        }
    }
    printf("%d",minlen==i?0:minlen);
    return 0;
}