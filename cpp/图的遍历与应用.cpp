#include<bits/stdc++.h>
using namespace std;

struct node{
    int idx;
    char name;
    node* next=NULL;
};
int vexnum,edgenum;
vector<node*> v[105];
int find(char x){
    for(int i=0;i<vexnum;i++){
        if(v[i][0]->name==x){
            return i;
        }
    }
    return -1;
}
int vd[105]={0};
int fa[105];
int findfa(int x){
    if(fa[x]==x){
        return x;
    }else{
        return fa[x]=findfa(fa[x]);
    }
}
void merge(int x,int y){
    int fx=findfa(x),fy=findfa(y);
    if(fx==fy){
        return;
    }else{
        fa[fy]=fx;
        return;
    }
}
void dfs(int x){
    if(vd[x]==0){
        cout<<v[x][0]->name<<" ";
        vd[x]=1;
        node* temp=v[x][0]->next;
        while(temp){
            dfs(temp->idx);
            temp=temp->next;
        }
    }
    return;
}
int main()
{
    
    cin>>vexnum>>edgenum;
    
    for(int i=0;i<vexnum;i++){
        node* temp=new node;
        char x;
        cin>>x;
        temp->idx=i;
        temp->name=x;
        v[i].push_back(temp);
    }
    for(int i=0;i<vexnum;i++){
        fa[i]=i;
    }
    for(int i=0;i<edgenum;i++){
        string s;
        cin>>s;
        int a=find(s[0]),b=find(s[1]);
        node* cur1=new node;
        node* cur2=new node;
        cur1->next=v[a][0]->next;
        v[a][0]->next=cur1;
        cur1->idx=b;
        cur2->next=v[b][0]->next;
        v[b][0]->next=cur2;
        cur2->idx=a;
        merge(a,b);
    }
    int first,second;
    cin>>first>>second;
    cout<<"please input the vexnum and arcnum"<<endl<<"vexnum="<<endl<<"arcnum="<<endl;
    cout<<endl;
    cout<<"enter the vexdata"<<endl;
    cout<<endl;
    cout<<"enter the edge"<<endl;
    for(int i=0;i<edgenum;i++){
        cout<<"input "<<i+1<<" edge:";
    }
    
    cout<<endl;
    cout<<"-------------------------------"<<endl;
    for(int i=0;i<vexnum;i++){
        cout<<"   AdjList["<<i<<"]   "<<v[i][0]->name;
        node* temp=v[i][0]->next;
        while(temp){
            cout<<"-->"<<temp->idx;
            temp=temp->next;
        }
        cout<<endl;
        }
        cout<<endl;
    dfs(0);
    cout<<endl;
    cout<<first<<" "<<second<<" ";
    if(findfa(first)==findfa(second)){
        cout<<"connect";    }else{
        cout<<"unconnect";
    }
    
    return 0;
}