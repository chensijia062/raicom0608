#include<bits/stdc++.h>
using namespace std;

bool judge(string s){
    int left=0,right=s.length()-1;
    while(left<=right){
        if(s[left]==s[right]){
            left++;
            right--;
        }else{
            return false;
        }
    }
    return true;
}
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }else{
        return a.first<b.first;
    }
}
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string words[n];
    vector<pair<int,int>> ret;
    for(int i=0;i<n;i++){
        getline(cin,words[i]);
        if(words[i]=="\"\"") words[i] = "";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i){
                continue;
            }
            string s=words[i]+words[j];
            
            if(judge(s)){
                ret.push_back({i,j});
            }
        }
    }
    sort(ret.begin(),ret.end(),cmp);
    cout<<ret.size()<<endl;
    for(int i=0;i<ret.size();i++){
        cout<<ret[i].first<<" "<<ret[i].second<<endl;    
    }
    return 0;
}