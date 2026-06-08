#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    if(s=="\"\""){
        s=="";
    }
    if(t=="\"\""){
        t=="";
        cout<<1;
        return 0;
    }
    int dp[1005]={0};
    dp[0]=1;
    for(int i=0;i<s.length();i++){
        for(int j=t.length()-1;j>=0;j--){
            if(s[i]==t[j]){
                dp[j+1]+=dp[j];
            }
        }
    }
    cout<<dp[t.length()];
    return 0;
}