#include<bits/stdc++.h>
using namespace std;

string num[10];
string digits;
string path;
vector<string> ret;
void dfs(int ceng){
    if(ceng==digits.length()){
        ret.push_back(path);
        return;
    }else{
        for(int i=0;i<num[digits[ceng]-'0'].length();i++){
            path.push_back(num[digits[ceng]-'0'][i]);
            dfs(ceng+1);
            path.pop_back();
        }
    }
}
int main()
{
    num[2]="abc";
    num[3]="def";
    num[4]="ghi";
    num[5]="jkl";
    num[6]="mno";
    num[7]="pqrs";
    num[8]="tuv";
    num[9]="wxyz";  
    cin>>digits;
    dfs(0);
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<endl;
    }
    
    return 0;
}