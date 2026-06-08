#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,cnt=0;
    int index[15]={0};
    cin>>n;
    deque<int> pai,l;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pai.push_back(a);
    }  
    while(pai.size()){
        if(l.empty()){
            l.push_back(pai.front());
            cnt++;
            index[pai.front()]++;
            pai.pop_front();
        }else{  
            if(index[pai.front()]){
                cnt++;
                while(l.back()!=pai.front()){
                    int temp=l.back();
                    index[temp]=0;
                    l.pop_back();
                    pai.push_back(temp);
                }
                l.pop_back();
                index[pai.front()]=0;
                pai.pop_front();
            }else{
                cnt++;
                l.push_back(pai.front());
                index[pai.front()]++;
                pai.pop_front();
            }
        }
    }
    cout<<cnt;
    return 0;
}