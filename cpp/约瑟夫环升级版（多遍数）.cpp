#include<bits/stdc++.h>
using namespace std;

struct LinkNode {
    int val;
    LinkNode* next;
};

int main() {
    int m;
    cin >> m;
    vector<int> currentQueue;
    for(int i = 1; i <= m; i++) {
        currentQueue.push_back(i);
    }
    vector<int> passwords;
    int x;
    char c;
    while(cin >> x) {
        passwords.push_back(x);
        c = cin.get();
        if(c == '\n' || c == EOF) break;
    }
    for(int i= 0; i< passwords.size(); i++) {
        int n = passwords[i];
        vector<int> newQueue; 
        int index=0;
        while(!currentQueue.empty()) {
            index = (index + n - 1) % currentQueue.size();
            newQueue.push_back(currentQueue[index]);
            currentQueue.erase(currentQueue.begin() + index);
        }
        currentQueue = newQueue;
    }
    for(int i = 0; i < currentQueue.size(); i++) {
        printf("%4d",currentQueue[i]);
    }
    cout << endl;  
    return 0;
}