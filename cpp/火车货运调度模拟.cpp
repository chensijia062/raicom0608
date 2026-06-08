#include<bits/stdc++.h>
using namespace std;

int destination, train, cnt = 0;

struct des {
    string name;
    int dis;
} des[55];

struct bridge {
    string to;
    string mark;
} t[55];

// 模拟队列（0位置是顶端）
deque<bridge> a, b, c; 
vector<string> result;

int getDis(string destName) {
    for (int i = 0; i < destination; i++) {
        if (des[i].name == destName) {
            return des[i].dis;
        }
    }
    return -1;
}

void re() {
    if (b.empty()) {
        return;
    }
    
    // 找到B中最远目的地且离顶最近的车厢
    int maxDis = -1, pos = -1;
    for (int j = 0; j < b.size(); j++) {
        int d = getDis(b[j].to);
        if (d > maxDis) {
            maxDis = d;
            pos = j;
        }
    }
    
    // 将pos及其上的车厢依次推进A（从B的0位置到pos位置）
    for (int i = 0; i <= pos; i++) {
        a.push_back(b[i]);
    }
    // 将B中pos之后的车厢向前移动
    for (int i = 0; i < pos + 1; i++) {
        b.pop_front();
    }
    
    // 此时A的顶端就是目标车厢
    bridge target = a.back();
    a.pop_back();
    
    // 检查A中是否还有未编组车厢
    if (a.empty()) {
        // 没有，直接放入结果
        result.push_back(target.mark);
    } else {
        // 有，把目标推进C，其余推进B，再从C回A
        c.push_back(target);
        while (!a.empty()) {
            // A的末尾插入B的头部
            b.push_front(a.back());
            a.pop_back();
            cnt++;
        }
        a.push_back(c.front());
        c.pop_front();
        result.push_back(a.back().mark);
        a.pop_back();
    }
    
    re();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> destination;
    for (int i = 0; i < destination; i++) {
        cin >> des[i].name >> des[i].dis;
    }
    
    cin >> train;
    for (int i = 0; i < train; i++) {
        cin >> t[i].to >> t[i].mark;
    }
    
    for (int i = 0; i < train; i++) {
        b.push_back(t[i]);
        cnt++;
    }
    
    re();
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
    cout << cnt;
    
    return 0;
}