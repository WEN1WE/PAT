/*
 * 1. 本题可以用层序遍历，然后比较
 * 2. 也可以使用深度优先搜索，求出最大的下标，然后与n进行比较，不同则二叉树没有满
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 30;
struct TreeNode {
    int left = -1;
    int right = -1;
};

int n;
vector<TreeNode> graph(MAX);
vector<int> leverorder;
bool table[MAX] = {false};

void getLeverorder(int root) {
    queue<int> q;
    q.push(root);
    
    while (!q.empty()) {
        int current = q.front();
        leverorder.push_back(current);
        if (graph[current].left != -1) {
            q.push(graph[current].left);
        }
        if (graph[current].right != -1) {
            q.push(graph[current].right);
        }
        q.pop();
    }
}

bool isCBT(int index) {
    int leftIndex = index * 2;
    int rightIndex = leftIndex + 1;
    int root = leverorder[index];

    if (leftIndex > n) {
        return true;
    }
    
    if (leverorder[leftIndex] != graph[root].left) {
        return false;
    }
    if (rightIndex <= n) {
        if (leverorder[rightIndex] != graph[root].right) {
            return false;
        }
    }
    
    return isCBT(leftIndex) && isCBT(rightIndex);
}

int main() {
    leverorder.push_back(-1);
    int root = 0; 
    string left, right;
    cin >> n;
    

    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        if (left != "-") {
            graph[i].left = stoi(left);
            table[graph[i].left] = true;
        }
        if (right != "-") {
            graph[i].right = stoi(right);
            table[graph[i].right] = true;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!table[i]) {
            root = i;
            break;
        }
    }
    
    getLeverorder(root);
    
    if (isCBT(1)) {
        printf("YES %d", leverorder[n]);
    } else {
        printf("NO %d", root);
    }
    return 0;
}
