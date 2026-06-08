#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a,vector<int> b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }else{
        return a[0]>b[0];
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> people(n);
    for(int i=0;i<n;i++){
        int h,k;
        cin>>h>>k;
        people[i].push_back(h);
        people[i].push_back(k);
    }
    sort(people.begin(),people.end(),cmp);
    vector<vector<int>> ret;
    for(int i=0;i<n;i++){
        ret.insert(ret.begin()+people[i][1],people[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ret[i][0]<<" "<<ret[i][1]<<endl;
    }
    return 0;
}