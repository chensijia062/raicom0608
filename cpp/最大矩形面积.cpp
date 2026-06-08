#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    stack<int> s;
    int ret=0;
    for(int i=0;i<n;i++){
        while(!s.empty()&&num[s.top()]>num[i]){
            int tp=s.top();
            s.pop();
            int width = s.empty()?i:(i-s.top()- 1);
            ret=max(ret,width*num[tp]);
        }
        s.push(i);
    }
    while(!s.empty()){
        int tp = s.top();
        s.pop();
        int width = s.empty() ? n : (n - s.top() - 1);
        ret = max(ret, width * num[tp]);
    }
    cout<<ret;
    return 0;
}