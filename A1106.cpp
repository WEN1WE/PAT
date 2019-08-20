/*
 * 1. 深度优先搜索
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> record[100010];

int cnt = 0;
int lowestLevel = 100010;

void dfs(int root, int level) {
    if (level > lowestLevel) {
        return;
    }
    
    if (record[root].empty()) {
        if (level < lowestLevel) {
            lowestLevel = level;
            cnt = 1;
        } else if (level == lowestLevel) {
            cnt++;
        }
    }
    
    for (auto e : record[root]) {
        dfs(e, level + 1);
    }
}

int main() {
    int n;
    double p, r, lowestPrice = 0;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;

    for (int i = 0; i < n; i++) {
        int k, child;
        scanf("%d", &k);
        
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            record[i].push_back(child);
        }
    }
    dfs(0, 0);
    lowestPrice = p * pow(1 + r, lowestLevel);
    printf("%.4f %d", lowestPrice, cnt);
    return 0;
    
}
