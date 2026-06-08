#include<bits/stdc++.h>
using namespace std;

int opposite(int x){
    if(x==1){
        return 2;
    }
    if(x==2){
        return 1;
    }
    if(x==3){
        return 4;
    }
    if(x==4){
        return 3;
    }
    return 0;
}
typedef pair<int,int> pii;
int main()
{
    string s;
    stack<pii> route;
    while(cin>>s){
        if(s=="0-0"){
            break;
        }
        if(route.empty()){
        int dir,dist;
        sscanf(s.c_str(),"%d-%d",&dir,&dist);
        route.push({dir,dist});
    }else{
        int dir,dist;
        sscanf(s.c_str(),"%d-%d",&dir,&dist);
        switch(dir){
            case 1:
            if(route.top().first==2){
                if(route.top().second<dist){
                    route.top().first=1;
                    route.top().second=abs(route.top().second-dist);
            }else if(route.top().second==dist){
                route.pop();
        }else{
            route.top().first=2;
            route.top().second=abs(route.top().second-dist);
        }
    }else{
        route.push({dir,dist});
    }
    break;
        case 2:
        if(route.top().first==1){
                if(route.top().second<dist){
                    route.top().first=2;
                    route.top().second=abs(route.top().second-dist);
            }else if(route.top().second==dist){
                route.pop();
        }else{
            route.top().first=1;
                    route.top().second=abs(route.top().second-dist);
        }
    }else{
        route.push({dir,dist});
    }
    break;
        case 3:
        if(route.top().first==4){
                if(route.top().second<dist){
                    route.top().first=3;
                    route.top().second=abs(route.top().second-dist);
            }else if(route.top().second==dist){
                route.pop();
        }else{
            route.top().first=4;
                    route.top().second=abs(route.top().second-dist);
        }
    }else{
        route.push({dir,dist});
    }
    break;
        case 4:
        if(route.top().first==3){
                if(route.top().second<dist){
                    route.top().first=4;
                    route.top().second=abs(route.top().second-dist);
            }else if(route.top().second==dist){
                route.pop();
        }else{
            route.top().first=3;
                    route.top().second=abs(route.top().second-dist);
        }
    }else{
        route.push({dir,dist});
    }
    break;
    }
}
    }
    vector<pii> ret;
    while(route.size()){
        pii temp=route.top();
        route.pop();
        while(route.size()){
        if(route.top().first==temp.first){
            temp.second+=route.top().second;
            route.pop();
        }else{
            break;
        }
        }
        temp.first=opposite(temp.first);
        cout<<temp.first<<"-"<<temp.second<<" ";
    }

    return 0;}
