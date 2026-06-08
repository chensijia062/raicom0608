#include<stdio.h>
#include<stdlib.h>

int main()
{
    int numcourses,m;
    int g[205][205]={0};
    int indegree[205]={0};
    scanf("%d%d",&numcourses,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[b][a]=1;
        indegree[a]++;
    }
    
    int queue[205],ret[205];
    int front=0,rear=0,retsize=0;
    for(int i=0;i<numcourses;i++){
        if(indegree[i]==0){
            queue[rear++]=i;
        }
    }
    if(rear==0){
        printf("0");
        return 0;
    }
    printf("%d\n",numcourses);
    while(front<rear){
        int temp=queue[front++];
        ret[retsize++]=temp;
        for(int i=0;i<numcourses;i++){
            if(g[temp][i]){
                indegree[i]--;
                if(indegree[i]==0){
                    queue[rear++]=i;
                }
            }
        }
    }
    for(int i=0;i<retsize;i++){
        printf("%d ",ret[i]);
    }
    return 0;
}