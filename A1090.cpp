/*
 * 1. 当输入数据比较大时，就是效率题
 * 2. 当对树进行深度优先搜索的时候，常把层次作为参数进行传递
 */


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> record[100010];
int maxDepth = 0;
int cnt = 0;

void dfs(int root, int depth) {
    if (depth == maxDepth) {
        cnt++;
    } else if (depth > maxDepth) {
        cnt = 1;
        maxDepth = depth;
    }
    
    if (record[root].empty()) {
        return;
    }
    for (auto e : record[root]) {
        dfs(e, depth + 1);
    }
}

int main() {
    int n, val = 0, root = 0;
    double p, r,  highestPrice = 0;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val == -1) {
            root = i;
            continue;
        }
        record[val].push_back(i);
    }
    dfs(root, 0);
    highestPrice = p * pow(1 + r, maxDepth);
    printf("%.2f %d", highestPrice, cnt);
    return 0;
}
