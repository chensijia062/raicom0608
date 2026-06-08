#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int k;
    scanf("%d",&k);
    int left=0,right=0;
    int ret=0,cnt=0;
    for(right=0;right<n;right++){
        if(nums[right]%2==1){
            cnt++;
            if(cnt==k){
                int l=left,r=right+1;
                while(nums[l]%2==0){
                    l++;
                }
                while(r<n&&nums[r]%2==0){
                    r++;
                }
                ret+=(l-left+1)*(r-right);
                while(nums[left]%2==0){
                    left++;
                }
                left++;
                cnt--;
            }
        }
    }
    printf("%d",ret);
    return 0;
}