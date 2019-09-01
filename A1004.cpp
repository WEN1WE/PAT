/*
 * 1. 深度优先搜索
 */


#include <iostream>
#include <vector>
using namespace std;

const int MAX = 110;
vector<int> graph[MAX];
int cnt[MAX] = {0};
int maxLevel = 0;

void dfs(int root, int level) {
    maxLevel = max(level, maxLevel);
    
    if (graph[root].empty()) {
        cnt[level]++;
        return;
    }
    
    for (auto e : graph[root]) {
        dfs(e, level + 1);
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int id, k, child;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            graph[id].push_back(child);
        }
    }
    dfs(1, 1);
    
    for (int i = 1; i <= maxLevel; i++) {
        if (i != 1) {
            printf(" ");
        }
        printf("%d", cnt[i]);
    }
    
    return 0;
}


#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX = 110;
vector<int> graph[MAX];
map<int, int> mp;
int deepest = 0;

void dfs(int root, int level) {
    if (graph[root].empty()) {
        deepest = max(deepest, level);
        mp[level]++;
    }
    for (auto e : graph[root]) {
        dfs(e, level + 1);
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int id, K, child;
        scanf("%d %d", &id, &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &child);
            graph[id].push_back(child);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= deepest; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", mp[i]);
    }
    printf("\n");
    return 0;
}
