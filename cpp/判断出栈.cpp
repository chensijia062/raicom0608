#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    int num1[num],num2[num];
    stack<int> s;
    for(int i=0;i<num;i++){
        cin>>num1[i];
    }
    for(int i=0;i<num;i++){
        cin>>num2[i];
    }
    int p1=0,p2=0;
    while(p2<num){
        if(p1<num){
        s.push(num1[p1++]);}
        while(s.size()&&s.top()==num2[p2]){
            s.pop();
            p2++;
        }
        if(s.size()&&s.top()!=num2[p2]&&p1==num){
                break;
            }
        }
    
    if(s.size()){
        cout<<0;
    }else{
        cout<<num;
    }
    return 0;
}