/*
 * 1. 记得对数组中的变量初始化
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000;

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    vector<int> graph[N];
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        bool flag = true;
        int n, v;
        scanf("%d", &n);
        bool table[MAX];
        fill(table, table + MAX, false);
        for (int j = 0; j < n; j++) {
            scanf("%d", &v);
            table[v] = true;
        }
        
        for (int j = 0; j < N; j++) {
            if (table[j]) {
                continue;
            } else {
                for (auto e : graph[j]) {
                    if (!table[e]) {
                        printf("No\n");
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        }
    }
    return 0;
}
