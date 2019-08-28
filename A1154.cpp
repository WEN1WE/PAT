/*
 * 1. 本题数据大，容易超时
 * 2. 使用邻接表存
 * 3. 递归要学会寻找等价条件，递归一定要找好等价条件，本题的等价条件想当然了
 * 4. 做复杂了，其实只用比较给的边就行
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX = 100100;
vector<vector<int>> graph(MAX);

bool dfs(int v, vector<int> & color, vector<bool> & visited) {
    if (visited[v] || graph[v].empty()) {
        visited[v] = true;
        return true;
    }
    visited[v] = true;
    for (auto w : graph[v]) {
        if (color[v] == color[w]) {
            return false;
        }
        if (!dfs(w, color, visited)) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    scanf("%d", &K);
    
    for (int i = 0; i < K; i++) {
        bool flag = true;
        vector<int> color(N);
        vector<bool> visited(MAX);
        map<int, bool> mp;
        for (int j = 0; j < N; j++) {
            scanf("%d", &color[j]);
            mp[color[j]] = true;
        }
        
        for (int j = 0; j < N; j++) {
            if (!visited[j] && !dfs(j, color, visited)) {
                flag = false;
                printf("No\n");
                break;
            }
        }
        if (flag) {
            printf("%d-coloring\n", mp.size());
        }
        
    }
    return 0;
}

