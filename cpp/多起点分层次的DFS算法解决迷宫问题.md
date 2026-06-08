//多起点分层次的DFS算法解决迷宫问题
//P274-275
#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
struct pos{
	int x,y;
};
int vd[105][105]={0};
int m,n;
void dfs(int island[][105],int x,int y){
	vd[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&vd[nx][ny]==0&&island[nx][ny]==1){
			dfs(island,nx,ny);
		}
	}
}
int bfs(int island[][105]){
	int ret=0;
	
	queue<pos> q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(vd[i][j]==1){
				q.push({i,j});
			}
		}
	}
	while(q.size()){
		int cnt=q.size();
		for(int i=0;i<cnt;i++){
			pos temp=q.front();
			q.pop();
			for(int j=0;j<4;j++){
				int nx=temp.x+dx[j];
				int ny=temp.y+dy[j];
				if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&vd[nx][ny]==0){
					if(island[nx][ny]==1){
						return ret;
					}else{
						q.push({nx,ny});
						vd[nx][ny]=1;
					}
				}
        	}
		}
		ret++;
	}
	return ret;
}
int main()
{
	
	cin>>m>>n;
	int island[105][105];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>island[i][j];
		}
	}
	int x,y,mark=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(island[i][j]==1){
				x=i;
				y=j;
				mark=1;
				break;
			}
			
		}
		if(mark==1){
				break;
			}
	}
	dfs(island,x,y);
	int ret=bfs(island);
	cout<<ret;
	return 0;
 } 
 