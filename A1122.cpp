/*
 * 1. 使用二维数组来存图的关系
 * 2. 还是数据没读完就返回的问题
 * 3. 本题使用set更加方便
 * 4. Hamiltonian 的特点是访问的总节点上为 n + 1,  而且每个节点被访问一次
 * 5. 理清题意，选择合适的结构
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, M, K;
const int MAX = 210;
bool graph[MAX][MAX];
map<int, bool> mp;

bool check(vector<int> & record) {
    if (record.size() != N + 1 || record[0] != record[record.size() - 1]) {
        return false;
    }
    for (int i = 0; i < N; i++) {
        if (graph[record[i]][record[i + 1]]) {
            mp[record[i]] = true;
            mp[record[i + 1]] = true;
        } else {
            return false;
        }
    }
    return mp.size() == N;
}


int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int n;
        scanf("%d", &n);
        vector<int> record(n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &record[j]);
        }
        if (check(record)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        mp.clear();
    }
    return 0;
}
