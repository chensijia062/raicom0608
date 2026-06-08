
#include<stdio.h>
#include<string.h>


    void change(char *str)
    {
        while(*str!='\0'){
            if(*str>='A'&&*str<='Z'){
                *str=(*str-'A'+3)%26+'A';
            }else if(*str>='a'&&*str<='z'){
                *str=(*str-'a'+3)%26+'a';
            }
            str++;
        }
    }

    int main(){
        char user[100];
        fgets(user,100,stdin);
        int len=strlen(user);
        if(user[len-1]=='\n'){
            user[len-1]='\0';
        }
        change(user);
        printf("%s",user);
    
    return 0;
    }
