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
vector<int> father(MAX);

void init() {
    for (int i = 0; i < father.size(); i++) {
        father[i] = i;
    }
}

int root(int k) {
    while (k != father[k]) {
        father[k] = father[father[k]];
        k = father[k];
    }
    return k;
}

void Union(int k1, int k2) {
    int root1 = root(k1);
    int root2 = root(k2);
    if (root1 != root2) {
        father[root1] = root2;
    }
}

int main() {
    init();
    int n, nOfBirds = 0;
    scanf("%d", &n);
    map<int, bool> mp;
    
    for (int i = 0; i < n; i++) {
        int k, id, first;
        scanf("%d", &k);
        scanf("%d", &first);
        nOfBirds = max(nOfBirds, first);
        for (int j = 1; j < k; j++) {
            scanf("%d", &id);
            nOfBirds = max(nOfBirds, id);
            Union(id, first);
        }
    }
    
    for (int i = 1; i <= nOfBirds; i++) {
        mp[root(i)] = true;
    }
    cout << mp.size() << " " << nOfBirds << endl;
    
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        if (root(id1) == root(id2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
