#include<bits/stdc++.h>
using namespace std;

int nums[100005];
void pu(int x,deque<int>& q){
    while(q.size()&&nums[x]>nums[q.back()]){
        q.pop_back();
    }
    q.push_back(x);
}
void po(int x,deque<int> &q){
    if(q.size()&&q.front()==x){
        q.pop_front();
    }
}
int main()
{
    int x,index=0,k;
    while(cin.peek()!='\n'&&cin>>x){
        nums[index++]=x;
    }
    cin>>k;
    vector<int> ret;
    deque<int> q;
    for(int i=0;i<k;i++){
        pu(i,q);
    }
    ret.push_back(nums[q.front()]);
    for(int i=k;i<index;i++){
        po(i-k,q);
        pu(i,q);
        ret.push_back(nums[q.front()]);
    }
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<" ";
    }
    return 0;
}