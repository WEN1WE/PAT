/*
 * 1. pow // #include <cmath>
 * 2. 本题主要考深度优先搜索
 * 3. 题目已经给了root = 0, 所以其实不用求
 * 4. 数据过大，使用邻接表来存储
 * 5. 使用map记录下销量 (map适合做记录的工作
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


#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const int MAX = 100010;
map<int, int> mp;
vector<int> graph[MAX];
double totalSales = 0;
double P, r;

void dfs(int root, int level) {
    if (mp.find(root) != mp.end()) {
        totalSales += P * pow(1 + r, level) * mp[root];
        return;
    }
    for (auto e : graph[root]) {
        dfs(e, level + 1);
    }
}

int main() {
    int N, root = -1;
    scanf("%d %lf %lf", &N, &P, &r);
    r = r / 100;
    vector<bool> table(N);
    
    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        if (K == 0) {
            int amount;
            scanf("%d", &amount);
            mp[i] = amount;
        } else {
            int child;
            for (int j = 0; j < K; j++) {
                scanf("%d", &child);
                table[child] = true;
                graph[i].push_back(child);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (!table[i]) {
            root = i;
        }
    }
    dfs(root, 0);
    printf("%.1f\n", totalSales);
    return 0;
}
