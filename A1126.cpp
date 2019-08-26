/*
 * 1. 要判断图的连通性，使用union find
 * 2. 注意边界1 0 的输入
 * 3. 对union find 初始化
 * 4. 也可以使用深度优先搜索
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> father(1000);

int root(int k) {
    while (k != father[k]) {
        father[k] = father[father[k]];
        k = father[k];
    }
    return k;
}

void Union(int p, int q) {
    int r1 = root(p);
    int r2 = root(q);
    
    if (r1 != r2) {
        father[r1] = r2;
    }
}

void init() {
    for (int i = 1; i <= father.size(); i++) {
        father[i] = i;
    }
}

int main() {
    bool flag = true;
    int n, m, size, count = 0;
    scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n + 1);
    vector<int> result;
    map<int, bool> mp;
    init();
    
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        Union(v1, v2);
    }

    for (int i = 1; i <= n; i++) {
        mp[root(i)] = true;
    }
    flag = mp.size() == 1;
    
    for (int i = 1; i <= n; i++) {
        size = graph[i].size();
        result.push_back(size);
        if (size % 2 != 0) {
            count++;
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    printf("\n");
    if (count == 0 && flag) {
        printf("Eulerian\n");
    } else if (count == 2 && flag) {
        printf("Semi-Eulerian\n");
    } else {
        printf("Non-Eulerian\n");
    }
    return 0;
}
