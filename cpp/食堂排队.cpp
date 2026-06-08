#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int student[n];
	for(int i=0;i<n;i++){
		cin>>student[i];
	} 
	sort(student,student+n);
	deque<int> t[m];
	for(int i=0;i<m;i++){
		t[i].push_back(0);
	}
	for(int i=0;i<n;i++){
		
		int temp=t[i%m].back();
		int x=temp+student[i];
		t[i%m].push_back(x);
		
	}
	
	int ret=0;
	for(int i=0;i<m;i++){
		while(t[i].size()>1){
			ret+=t[i].front();
			t[i].pop_front();
		}
	}
	cout<<ret;
	
	return 0;
}