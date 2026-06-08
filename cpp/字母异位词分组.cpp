#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    map<string, vector<int>> groups;
    for (int i = 0; i < n; ++i) {
        string key = strs[i];
        sort(key.begin(), key.end());
        groups[key].push_back(i);
    }

    // 收集每组的首元素下标和组成员下标
    vector<pair<int, vector<int>>> order;
    for (auto& p : groups) {
        order.push_back({p.second[0], p.second});
    }
    sort(order.begin(), order.end()); // 按首元素下标升序

    for (auto& g : order) {
        for (int idx : g.second) {
            cout << strs[idx] << " ";
        }
        cout << endl;
    }
    return 0;
}