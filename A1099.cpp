/*
 * 1. 二叉搜索树与深度优先搜索结合，有统计的功能
 */


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int value;
    int left;
    int right;
};
const int MAX = 110;
vector<int> inorder;
vector<int> leverorder;
vector<TreeNode> graph(MAX);

int cnt = 0;

void dfs(int root) {
    if (root == -1) {
        return;
    }
    dfs(graph[root].left);
    graph[root].value = inorder[cnt++];
    dfs(graph[root].right);
}

void getLeverorder(int root) {
    queue<int> q;
    q.push(root);
    
    while (!q.empty()) {
        int current = q.front();
        leverorder.push_back(graph[current].value);
        if (graph[current].left != -1) {
            q.push(graph[current].left);
        }
        if (graph[current].right != -1) {
            q.push(graph[current].right);
        }
        q.pop();
    }
}

int main() {
    int n, value;
    cin >> n;
    int left[n], right[n];
    
    for (int i = 0; i < n; i++) {
        cin >> graph[i].left >> graph[i].right;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        inorder.push_back(value);
    }
    sort(inorder.begin(), inorder.end());
    dfs(0);
    getLeverorder(0);
    
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", leverorder[i]);
    }
    
    return 0;
    
}
