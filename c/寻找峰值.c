#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int n;
    scanf("%d",&n);
    int nums[n+2];
    nums[0]=nums[n+1]=INT_MIN;
    for(int i=1;i<=n;i++){
        scanf("%d",&nums[i]);
    }
    int left=1,right=n,mid;
    while(left<right){
        mid=(left+right)/2;
        if(nums[mid]>nums[mid+1]){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    printf("%d",left-1);
    return 0;
}