/*
 * 1. 使用深度优先搜索，进行数块
 * 2. 使用邻接表进行存储图
 * 3. 根据划分了多少部分，来确定修多少条路
 */

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
int removed;

void dfs(int v, vector<bool> & visited) {
    visited[v] = true;
    for (auto e : graph[v]) {
        if (!visited[e] && e != removed) {
            dfs(e, visited);
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    graph.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    for (int i = 0; i < k; i++) {
        int component = 0;
        vector<bool> visited(n + 1);
        scanf("%d", &removed);
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && j != removed) {
                component++;
                dfs(j, visited);
            }
        }
        cout << component - 1 << endl;
    }
    
    return 0;
}
