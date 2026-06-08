#include<stdio.h>
#include<string.h>

int main()
{
    char str[100001];
    scanf("%s",str);
    int len=strlen(str);
    int ret=0;
    int left[26]={0};
    int right[26]={0};
    int leftkind=0;
    int rightkind=0;
    for(int i=0;i<len;i++){
        int idx=str[i]-'a';
        if(right[idx]==0){
            rightkind++;
        }
        right[idx]++;
    }
    for(int i=0;i<len-1;i++){
        int idx=str[i]-'a';
        if(left[idx]==0){
            leftkind++;
        }
        left[idx]++;
        right[idx]--;
        if(right[idx]==0){
            rightkind--;
        }
        if(leftkind==rightkind){
            ret++;
        }
    }
        printf("%d\n",ret);
    return 0;
}