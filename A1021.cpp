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
#include <map>
using namespace std;

vector<int> father;
vector<vector<int>> graph;
set<int> result;

int root(int i) {
    while (i != father[i]) {
        father[i] = father[father[i]];
        i = father[i];
    }
    return i;
}

void Union(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i != j) {
        father[i] = j;
    }
}

void init(int n) {
    father.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int deepest = 0;
int tempDeepest = 0;

void dfs(int v, int preV, int deep) {
    if (deep > tempDeepest) {
        tempDeepest = deep;
    }
    for (auto e : graph[v]) {
        if (e != preV) {
            dfs(e, v, deep + 1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    graph.resize(n + 1);
    map<int, bool> mp;
    
    for (int i = 0; i < n - 1; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
        Union(node1, node2);
    }
    
    for (int i = 1; i <= n; i++) {
        mp[root(i)] = true;
    }
    
    if (mp.size() != 1) {
        printf("Error: %d components\n", mp.size());
        return 0;
    }
    
    for (int i = 1; i <= n; i++) {
        dfs(i, 0, 1);
        if (tempDeepest > deepest) {
            deepest = tempDeepest;
            result.clear();
            result.insert(i);
        } else if (tempDeepest == deepest) {
            result.insert(i);
        }
        tempDeepest = 0;
    }
    
    for (auto e : result) {
        cout << e << endl;
    }
    
    return 0;
}
