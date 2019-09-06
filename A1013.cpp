/*
 * 1. 使用深度优先搜索，进行数块
 * 2. 使用邻接表进行存储图
 * 3. 根据划分了多少部分，来确定修多少条路
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1010;
vector<vector<int>> graph(MAX);
int visited[MAX];
int occupied;

void dfs(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    for (auto e : graph[v]) {
        if (e != occupied)
            dfs(e);
    }
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    
    for (int i = 0; i < M; i++) {
        int city1, city2;
        scanf("%d %d", &city1, &city2);
        graph[city1].push_back(city2);
        graph[city2].push_back(city1);
    }
    
    for (int i = 0; i < K; i++) {
        int cnt = 0;
        scanf("%d", &occupied);
        
        for (int j = 1; j <= N; j++) {
            if (j != occupied && !visited[j]) {
                cnt++;
                dfs(j);
            }
        }
        printf("%d\n", cnt - 1);
        fill(visited, visited + MAX, false);
    }
    return 0;
}
