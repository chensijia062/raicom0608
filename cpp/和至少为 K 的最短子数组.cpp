#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,k,ret=100005;
    vector<int> nums;
    while(cin.peek()!='\n'&&cin>>x){
        nums.push_back(x);
    }
    cin>>k;
    deque<int> q;
    vector<int> prefix;
    prefix.push_back(0);
    for(int i=0;i<nums.size();i++){
        prefix.push_back(prefix.back()+nums[i]);
    }
    for(int i=0;i<prefix.size();i++){
        if(q.empty()){
            q.push_back(i);
        }else{
            while(q.size()&&prefix[i]-prefix[q.front()]>=k){
                ret=min(ret,i-q.front());
                q.pop_front();
            }
            while(q.size()&&prefix[i]<=prefix[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
    }
    if(ret==100005){
        cout<<-1;
    }else{
        cout<<ret;
    }
    return 0;
}