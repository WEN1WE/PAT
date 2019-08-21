/*
 * 1. 使用邻接表来存储关系
 * 2. 对二维数组进行排序 sort(result, result + record.size(), cmp); // result 为二维数组
 * 3. path 不用记录整个图的路径，只用记录一段就行
 * 4. 在开始之前对孩子进行排序，这样深度优先搜索的输出就是排序后的结果
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 110;
int s;
vector<int> weight(MAX);
vector<int> graph[MAX];
vector<int> path(MAX);
vector<int> record;
vector<int> result[MAX];

void dfs(int root, int total) {
    if (total > s) {
        return;
    }
    if (total == s && graph[root].empty()) {
        record.push_back(root);
        return;
    }
    for (auto e : graph[root]) {
        path[e] = root;
        dfs(e, total + weight[e]);
    }
}

bool cmp(vector<int> & result1, vector<int> & result2) {
    int len = min(result1.size(), result2.size());
    for (int i = 0; i < len; i++) {
        if (result1[i] < result2[i]) {
            return false;
        } else if (result1[i] > result2[i]) {
            return true;
        } else {
            continue;
        }
    }
    return false;
}

int main() {
    path[0] = -1;
    int n, m;
    cin >> n >> m >> s;

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    
    for (int i = 0; i < m; i++) {
        int id, k, child;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            graph[id].push_back(child);
        }
    }
    
    dfs(0, weight[0]);
    
    for (int i = 0; i < record.size(); i++) {
        int current = record[i];
        while (current != -1) {
            result[i].push_back(weight[current]);
            current = path[current];
        }
        reverse(result[i].begin(), result[i].end());
    }
    
    sort(result, result + record.size(), cmp);
    
    for (int i = 0; i < record.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
