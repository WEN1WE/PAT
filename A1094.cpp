/*
 * 1. 题目有一个边界，只有一个节点
 * 2. 对于树的深度优先搜索，传递一个level参数
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 110;
vector<int> record[MAX];
int cnt[MAX] = {0};

void dfs(int root, int level) {
    cnt[level]++;
    if (record[root].empty()) {
        return;
    }
    for (auto e : record[root]) {
        dfs(e, level + 1);
    }
}

int main() {
    int n, m, level = 1, largest = 0;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int id, k, child;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            record[id].push_back(child);
        }
    }
    
    dfs(1, 1);
    for (int i = 0; i < n; i++) {
        if (cnt[i] > largest) {
            largest = cnt[i];
            level = i;
        }
    }
    cout << largest << " " << level;
    
    return 0;
}
