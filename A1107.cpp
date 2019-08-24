/*
 * 1. Union要大写，否则有歧义
 * 2. 本题优化了权重，并且路径压缩了
 * 3. 也可以不收集数据，一个变量保存上次喜欢该爱好的人，把他们都连起来就行了
 * 4. map<int, int> mp // 此时map自己初始化了为0
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> id;
vector<int> sz;

int root(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

bool connected(int p, int q) {
    return root(p) == root(q);
}

void Union(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i == j) {
        return;
    }
    id[i] = j;
    
    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

void init(int n) {
    id.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    map<int, vector<int>> mp;
    map<int, int> clusterCount;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        int k, h;
        scanf("%d: ", &k);
        
        for (int j = 0; j < k; j++) {
            scanf("%d", &h);
            mp[h].push_back(i);
        }
    }
    
    for (auto e : mp) {
        for (int i = 1; i < e.second.size(); i++) {
            Union(e.second[0], e.second[i]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        clusterCount[root(i)]++;
    }
    
    for (auto e : clusterCount) {
        result.push_back(e.second);
    }
    
    sort(result.begin(), result.end(), cmp);
    printf("%d\n", clusterCount.size());
    for (int i = 0; i < result.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    return 0;
}
