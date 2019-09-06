/*
 * 1. union find 一定要初始化
 * 2. 当联通图的边数为顶点数减1是，则图无环
 * 3. set 可以进行clear 
 * 4. set 与 insert 配套
 * 5. 代码要考虑n == 1 的情况
 * 6. 程序容易超时
 * 7. 弄清楚每次递归做什么事情
 * 8. 使用深度优先搜索判断连通性，方便
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX = 10010;
vector<vector<int>> graph(MAX);
int visited[MAX];
int tempDeepest = -1;
int deepest = -1;

void dfs(int v, int deep) {
    if (visited[v]) {
        return;
    }
    tempDeepest = max(deep, tempDeepest);
    visited[v] = true;
    for (auto e : graph[v]) {
        dfs(e, deep + 1);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    set<int> result;
    
    for (int i = 0; i < N - 1; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int components = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, 1);
        }
    }
    if (components != 1) {
        printf("Error: %d components", components);
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        fill(visited, visited + MAX, false);
        tempDeepest = -1;
        dfs(i, 1);
        
        if (tempDeepest > deepest) {
            deepest = tempDeepest;
            result.clear();
            result.insert(i);
        } else if (tempDeepest == deepest) {
            result.insert(i);
        }
    }
    
    for (auto e : result) {
        printf("%d\n", e);
    }
    
    return 0;
}
