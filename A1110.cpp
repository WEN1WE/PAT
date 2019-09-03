/*
 * 1. 本题使用层序遍历来判断满二叉树的方法很厉害
 * 2. 判断满二叉树不能使用递归，左满 右满 与 整个树满不等价
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int left = -1;
    int right = -1;
};
vector<TreeNode> graph;
vector<int> levelorder;

bool bfs(int root) {
    queue<int> q;
    q.push(root);
    bool flag = true;
    
    while (!q.empty()) {
        int node = q.front();
        levelorder.push_back(node);
        q.pop();
        if (graph[node].left != -1) {
            if (flag) {
                q.push(graph[node].left);
            }
            else {
                return false;
            }
        } else {
            flag = false;
        }
        if (graph[node].right != -1) {
            if (flag) {
                q.push(graph[node].right);
            }
            else {
                return false;
            }
        } else {
            flag = false;
        }
    }
    return true;
}

int main() {
    int N, root = -1;
    scanf("%d", &N);
    graph.resize(N);
    vector<bool> table(N);
    
    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 != "-") {
            int node = stoi(s1);
            graph[i].left = node;
            table[node] = true;
            
        }
        if (s2 != "-") {
            int node = stoi(s2);
            graph[i].right = node;
            table[node] = true;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (!table[i]) {
            root = i;
        }
    }
    
    if (bfs(root)) {
        printf("YES %d", levelorder[N - 1]);
    } else {
        printf("NO %d", root);
    }
    
}
