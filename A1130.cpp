/*
 * 1. 如何去外层的括号
 * 2. 深度优先，递归解决
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 30;
struct TreeNode {
    string data;
    int left;
    int right;
};
vector<TreeNode> tree(MAX);

string dfs(int root) {
    if (root == -1) {
        return "";
    }
    if (tree[root].left == -1 && tree[root].right == -1) {
        return tree[root].data;
    }
    return "(" + dfs(tree[root].left) + tree[root].data + dfs(tree[root].right) + ")";
}

int main() {
    int n, root = -1;
    cin >> n;
    bool table[MAX] = {false};
    
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].data >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1) {
            table[tree[i].left] = true;
        }
        if (tree[i].right != -1) {
            table[tree[i].right] = true;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!table[i]) {
            root = i;
        }
    }
    
    string result = dfs(root);
    if (result[0] == '(') {
        int len = result.length();
        result = result.substr(1, len - 2);
    }
    cout << result;
    return 0;
}
