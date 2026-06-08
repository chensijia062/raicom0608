#include<bits/stdc++.h>
using namespace std;

struct f{
    string name;
    int idx,vt=0;
};

int main()
{
    int num,index=0;
    vector<f> fun[2000];  // 保留你的数组
    f s;
    stack<f> st;
    vector<string> run_order; // 运行时调用序（原题要求）
    map<string, int> name2idx; // 函数名 → 唯一索引（关键！）

    while(1){
        cin>>num;
        if(num==5){
            cin>>s.name;

            // 第一次出现的函数，分配唯一索引
            if(name2idx.find(s.name) == name2idx.end()){
                name2idx[s.name] = index;
                fun[index].push_back({s.name, index});
                run_order.push_back(s.name); // 记录运行顺序
                index++;
            }

            // 当前栈顶 = 调用者（算法提示！）
            if(!st.empty()){
                f caller = st.top();
                int c_idx = name2idx[caller.name];
                // 去重：只加一次
                bool has = false;
                for(int j=1; j<fun[c_idx].size(); j++){
                    if(fun[c_idx][j].name == s.name){
                        has = true;
                        break;
                    }
                }
                if(!has){
                    fun[c_idx].push_back({s.name});
                }
            }

            st.push({s.name}); // 入栈
        }else{
            if(!st.empty()) st.pop();
        }
        if(st.empty()) break;
    }

    // 按原题要求：运行时调用序输出
    for(string name : run_order){
        int i = name2idx[name];
        if(fun[i].size() > 1){
            cout<<fun[i][0].name<<":";
            for(int j=1; j<fun[i].size(); j++){
                cout<<fun[i][j].name;
                if(j != fun[i].size()-1) cout<<";";
            }
            cout<<endl;
        }
    }
    return 0;
}