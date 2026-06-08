#include<bits/stdc++.h>
using namespace std;

struct box{
    int x,y,dir=0;
};
int main()
{
    int m,n;
    cin>>m>>n;
    int mg[105][105];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>mg[i][j];
        }
    }
    stack<box> s;
    s.push({1,1,0});
    mg[1][1]=1;
    while(s.size()){
        box temp=s.top();
        s.top().dir++;
        int x=temp.x,y=temp.y;
        if(x==m&&y==n){
            cout<<"("<<temp.x<<","<<temp.y<<","<<0<<")";
            return 0;
        }
        while(temp.dir<=4){
            int nx=x,ny=y;
            switch(temp.dir){
                case 1:
                ny++;break;
                case 2:
                nx++;break;
                case 3:
                ny--;break;
                case 4:
                nx--;break;
            }
            if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&mg[nx][ny]==0){
                s.top().dir=temp.dir;
                cout<<"("<<x<<","<<y<<","<<temp.dir<<")";
                mg[nx][ny]=1;
                s.push({nx,ny,0});
                
                break;
            }else{
                temp.dir++;
            }
        }
        if(temp.dir>4){
            s.pop();
        }
    }
    return 0;
}
