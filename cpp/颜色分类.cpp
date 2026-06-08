#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> n;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='['||s[i]==']'||s[i]==','){
            continue;
        }else{
            n.push_back(s[i]-'0');
        }
    }
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n.size()-i-1;j++){
                if(n[j]>n[j+1]){
                    swap(n[j],n[j+1]);
                }
            }
        }
        cout<<"[";
        for(int i=0;i<n.size();i++){
            if(i==0){
                cout<<n[i];
            }else{
            cout<<","<<n[i];
        }
        }
        cout<<']';
    return 0;
}