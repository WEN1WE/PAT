/*
 * 1. set 放入元素用insert()
 * 2. printf("%%");  // 输入一个%
 * 3. 多使用一个set 超时
 */
#include <iostream>
#include <set>
using namespace std;

const int MAX = 60;

double getSimilarity(set<int> & s1, set<int> & s2) {
    int count = 0;
    for (auto e : s1) {
        if (s2.find(e) != s2.end()) {
            count++;
        }
    }
    return count * 100.0 / (s1.size() + s2.size() - count) ;
}


int main() {
    int N, M, K;
    double similarity;
    scanf("%d", &N);
    set<int> record[MAX];

    for (int i = 1; i <= N; i++) {
        int n = 0;
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &n);
            record[i].insert(n);
        }
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        similarity = getSimilarity(record[n1], record[n2]);
        printf("%.1f%%\n", similarity);
    }
    return 0;
}
