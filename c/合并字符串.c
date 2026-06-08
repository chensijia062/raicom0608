#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *str_bin(char* str1,char* str2){
    int len1=strlen(str1),len2=strlen(str2);
    char *ret=(char*)malloc(sizeof(char)*(len1+len2+1));
    int point1=0,point2=0,index=0;
    while(point1<len1&&point2<len2){
        if(str1[point1]<str2[point2]){
            ret[index++]=str1[point1++];
        }else{
            ret[index++]=str2[point2++];
        }
    }
    while(point1<len1){
        ret[index++]=str1[point1++];
    }
    while(point2<len2){
        ret[index++]=str2[point2++];
    }
    ret[index]='\0';
    return ret;
}
int main()
{
    char str1[101],str2[101];
    scanf("%s",str1);
    scanf("%s",str2);
    char *ret=str_bin(str1,str2);
    printf("%s",ret);
    free(ret);
    ret=NULL;
    return 0;
}