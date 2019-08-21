/*
 * 1. 本题使用深度优先搜索进行统计
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int MAX = 1010;
vector<int> inorder;
vector<int> CBT(MAX);
int cnt = 0;

void dfs(int root) {
    if (root > n) {
        return;
    }
    dfs(root * 2);
    CBT[root] = inorder[cnt++];
    dfs(root * 2 + 1);
}

int main() {
    int value;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        inorder.push_back(value);
    }
    
    sort(inorder.begin(), inorder.end());
    
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            printf(" ");
        } 
        printf("%d", CBT[i]);
    }
    return 0;
}
