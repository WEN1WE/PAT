/*
 * 1. union find 的使用
 * 2. 思考union find 如何知道有多少根
 * 3. union find 记得初始化
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX = 10010;
vector<int> parent(MAX);

void init() {
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
    }
}

int root(int i) {
    while (i != parent[i]) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void Union(int i, int j) {
    int r1 = root(i);
    int r2 = root(j);
    if (r1 != r2) {
        parent[r1] = r2;
    }
}

int main() {
    init();
    int N, K, Q, first, other;
    scanf("%d", &N);
    map<int, bool> birdCount;
    map<int, bool> treeCount;
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &K, &first);
        birdCount[first] = true;
        for (int j = 1; j < K; j++) {
            scanf("%d", &other);
            birdCount[other] = true;
            Union(first, other);
        }
    }
    
    for (auto e : birdCount) {
        treeCount[root(e.first)] = true;
    }
    printf("%d %d\n", treeCount.size(), birdCount.size());
    scanf("%d", &Q);
    
    for (int i = 0; i < Q; i++) {
        int b1, b2;
        scanf("%d %d", &b1, &b2);
        if (root(b1) == root(b2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
