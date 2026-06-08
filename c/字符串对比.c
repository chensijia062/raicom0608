#include<stdio.h>
#include<string.h>

int main()
{
    char str1[11],str2[11];
    scanf("%s",str1);
    scanf("%s",str2);
    int len1=strlen(str1),len2=strlen(str2);
    if(len1!=len2){
        printf("1");
        return 0;
    }else{
        for(int i=0;i<len1;i++){
            if((str1[i]==str2[i])||(str1[i]==str2[i]+32||str1[i]+32==str2[i])){
                continue;
            }else{
                printf("4");
                return 0;
            }
        }
        for(int i=0;i<len1;i++){
            if(str1[i]!=str2[i]){
                printf("3");
                return 0;
            }
        }
    }
        printf("2");
    return 0;
}