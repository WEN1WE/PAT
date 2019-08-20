/*
 * 1. pow // #include <cmath>
 * 2. 本题主要考深度优先搜索
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 100010;
bool table[MAX] = {false};
vector<int> record[MAX];

double dfs(int root, int level, double r) {
    double totalSales = 0;
    int len = record[root][0];
    if (len == 0) {
        return record[root][1] * pow(1 + r, level);
    }
    for (int i = 1; i <= len; i++) {
        totalSales += dfs(record[root][i], level + 1, r);
    }
    return totalSales;
}


int main() {
    ios::sync_with_stdio(false);
    int n, val, len, root = 0;
    double p, r;
    double totalSales = 0;
    
    scanf("%d %lf %lf", &n, &p, &r);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &len);
        if (len == 0) {
            record[i].push_back(0);
            scanf("%d", &val);
            record[i].push_back(val);
        } else {
            record[i].push_back(len);
            for (int j = 0; j < len; j++) {
                scanf("%d", &val);
                table[val] = true;
                record[i].push_back(val);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!table[i]) {
            root = i;
            break;
        }
    }
    
    totalSales = p * dfs(root, 0, r / 100);
    printf("%.1f", totalSales);
    return 0;
}
