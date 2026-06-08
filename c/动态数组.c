
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    if(a==NULL){
        return 1;
    }
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
   //冒泡排序
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }

        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    free(a);
    a=NULL;

    return 0;
}