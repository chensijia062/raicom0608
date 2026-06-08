#include <bits/stdc++.h>
using namespace std;

struct tree {
    string val;
    tree* left;
    tree* right;
};
void preorder(tree* root, vector<string>& ret) {
    if (!root) return;
    ret.push_back(root->val);
    preorder(root->left, ret);
    preorder(root->right, ret);
}
void invert(tree* root) {
    if (!root) return;
    swap(root->left, root->right);
    invert(root->left);
    invert(root->right);
}
int main() {
    string s;
    cin >> s;
    vector<string> v;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == ']') continue;
        if (s[i] == ',') {
            v.push_back(temp);
            temp.clear();
            continue;
        }
        temp += s[i];
    }
    if (!temp.empty()) v.push_back(temp);
    tree* root = new tree;
    root->val = v[0];
    queue<tree*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < v.size()) {
        tree* cur = q.front();
        q.pop();
        if (i < v.size() && v[i] != "null") {
            cur->left = new tree;
            cur->left->val = v[i];
            cur->left->left = cur->left->right = NULL;
            q.push(cur->left);
        } else {
            cur->left = NULL;
        }
        i++;
        if (i < v.size() && v[i] != "null") {
            cur->right = new tree;
            cur->right->val = v[i];
            cur->right->left = cur->right->right = NULL;
            q.push(cur->right);
        } else {
            cur->right = NULL;
        }
        i++;
    }
    vector<string> ret1, ret2;
    preorder(root, ret1);
    invert(root);
    preorder(root, ret2);
    cout << "原树的前序遍历: ";
    for (auto& x : ret1) cout << x << " ";
    cout << endl;
    cout << "翻转后的前序遍历: ";
    for (auto& x : ret2) cout << x << " ";
    cout << endl;
    return 0;
}