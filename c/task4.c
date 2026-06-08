
#include<stdio.h>
int main()
{
    //输出结果的范围是0~65535
    int d,e;
    unsigned int c;
    printf("请输入整数d,e\n");
    scanf("%d %d",&d,&e);
    if(d>65535||e>65535||d<0||e<0){
        printf("停止计算");
    }else{
        unsigned short int a=d;
        unsigned short int b=e;
        c=a*b%65537;
        printf("c=%u",c);
    }
    return 0;
}