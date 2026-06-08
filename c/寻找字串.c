
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char *lon=(char*)malloc(100*sizeof(char));
    char *sht=(char*)malloc(100*sizeof(char));
    if(lon==NULL||sht==NULL){
        return 1;
    }
    fgets(lon,100,stdin);
    int len=strlen(lon);
    if(lon[len-1]=='\n'){
        lon[len-1]='\0';
        len--;
    }
    fgets(sht,100,stdin);
    int plen=strlen(sht);
    if(sht[plen-1]=='\n'){
        sht[plen-1]='\0';
        plen--;
    }
    int cnt=0;
    int k,pcnt=0;
    for(int i=0;i<len;i++){
        if(lon[i]==sht[0]){
            k=i;
            break;
        }
    }
    for(int i=k;i<len;i+=plen){
        for(int j=i,m=0;m<plen;j++,m++){
            if(lon[j]==sht[m]){
                pcnt++;
                cnt++;
            }
        }
        if(pcnt==plen){
            pcnt=0;
        }else{
            cnt-=pcnt;
            pcnt=0;
        }
    }
    printf("%d",cnt/plen);
    free(lon);
    free(sht);
    lon=NULL;
    sht=NULL;
    return 0;
}