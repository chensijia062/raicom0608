#include<stdio.h>
#include<string.h>

int main()
{
    char stack[101];
    int stacktop=0;
    char str[101];
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]=='s'){
            stack[stacktop++]=str[i];
        }else{
            if(stacktop==0){
                printf("0");
                return 0;
            }else{
                stacktop--;
            }
        }
    }
    if(stacktop==0){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}