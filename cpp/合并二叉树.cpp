#include<bits/stdc++.h>
using namespace std;

int main()
{
    string root1,root2;
    cin>>root1>>root2;
    vector<int> r1,r2;
    for(int i=0;i<root1.length();i++){
        if(root1[i]!='['&&root1[i]!=']'&&root1[i]!=','&&root1[i]!='n'&&root1[i]!='u'&&root1[i]!='l'){
            r1.push_back(root1[i]-'0');
        }
        if(root1[i]=='n'){
            r1.push_back(0);
        }
    }
    for(int i=0;i<root2.length();i++){
        if(root2[i]!='['&&root2[i]!=']'&&root2[i]!=','&&root2[i]!='n'&&root2[i]!='u'&&root2[i]!='l'){
            r2.push_back(root2[i]-'0');
        }
        if(root2[i]=='n'){
            r2.push_back(0);
        }
    }
    vector<int> ret;
    int p1=0,p2=0;
    while(p1<r1.size()&&p2<r2.size()){
        ret.push_back(r1[p1]+r2[p2]);
        p1++;
        p2++;
    }
    while(p1==r1.size()&&p2<r2.size()){
        ret.push_back(r2[p2]);
        p2++;
    }
    while(p2==r2.size()&&p1<r1.size()){
        ret.push_back(r1[p1]);
        p1++;
    }
   
    cout<<'[';
    for(int i=0;i<ret.size();i++){
        if(ret[i]>0){
            if(i==0){
                cout<<ret[i];
            }else{
                cout<<","<<ret[i];
            }
        }else{
            if(i==0){
                cout<<"null";
            }
            cout<<","<<"null";
        }
    }
    cout<<"]";
    return 0;
}