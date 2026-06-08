
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int *num=(int*)malloc(6*sizeof(int));
    int *a=(int*)malloc(6*sizeof(int));
    if(num==NULL||a==NULL){
        return 1;
    }
    srand(time(NULL));
    for(int i=0;i<6;i++){
        num[i]=rand()%10;
    }
    
    for(int i=0;i<6;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(int i=0;i<6;i++){
        if(*(num+i)==*(a+i)){
            cnt++;
        }
    }
    printf("%d",cnt);
    printf("\n");
    for(int i=0;i<6;i++){
        printf("%d",num[i]);
    }
    printf("\n");
    free(num);
    free(a);
    num=NULL;
    a=NULL;
    return 0;
}