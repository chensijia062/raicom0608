#include<bits/stdc++.h>
using namespace std;

vector<int> num;
vector<int> ret;
int findmax(int left,int right){
    int maxv=0,temp;
    for(int i=left;i<=right;i++){
        if(num[i]>maxv){
            maxv=num[i];
            temp=i;
        }
    }
    return temp;
}
void r(int k){
    int left=0,right=k-1;
    while(left<right){
        swap(num[left],num[right]);
        left++;
        right--;
    }
    return;
}
void reverse(int left,int right){
    if(left>=right){
        return;
    }
    int k=findmax(left,right);
    if(k==0){
        ret.push_back(right-left+1);
        r(right-left+1);
        reverse(left,right-1);
    }else{
        ret.push_back(k+1);
        r(k+1);
        reverse(left,right);
    }
}
int main()
{
    string s;
    getline(cin,s);
    
    string temp;
    for(int i=0;i<s.length();i++){
        if(s[i]=='['||s[i]==']'){
            continue;
        }else if(s[i]==','){
            num.push_back(stoi(temp));
            temp.clear();
            continue;
        }
        temp+=s[i];
    }
    if(temp.length()){
        num.push_back(stoi(temp));
    }
    reverse(0,num.size()-1);
    for(int i=0;i<ret.size()-1;i++){
        if(ret[i]==ret[i+1]){
            ret[i]=ret[i+1]=-1;
            i++;
        }
    }
    cout<<'[';
    bool mark=false;
    for(int i=0;i<ret.size();i++){
        if(ret[i]!=-1){
        if(mark==false){
            cout<<ret[i];
            mark=true;
        }else{
            cout<<','<<ret[i];
        }
    }
}
    cout<<']';
    return 0;
}