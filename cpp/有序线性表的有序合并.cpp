#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    cin>>x;
    int a[x];
    for(int i=0;i<x;i++){
        cin>>a[i];
    }
    cin>>y;
    int b[y];
    for(int i=0;i<y;i++){
        cin>>b[i];
    }
    int ret[x+y];
    int i=0,j=0,index=0;
    while(i<x&&j<y){
        if(a[i]<=b[j]){
            ret[index++]=a[i];
            i++;
        }else{
            ret[index++]=b[j];
            j++;
        }
    }
    while(i<x){
        ret[index++]=a[i];
        i++;
    }
    while(j<y){
        ret[index++]=b[j];
        j++;
    }
    for(int i=0;i<index;i++){
        cout<<ret[i]<<" ";
    }
    return 0;
}