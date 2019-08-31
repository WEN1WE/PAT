/*
 * 1. 利用孩子节点的序号比父亲节点大的原理
 */

#include <iostream> 
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    vector<int> graph[N + 1];
    vector<int> result;
    
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
    }
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        bool flag = true;
        int v;
        map<int, int> mp;
        for (int j = 0; j < N; j++) {
            scanf("%d", &v);
            mp[v] = j;
        }
        
        for (int pre = 1; pre <= N; pre++) {
            for (auto next : graph[pre]) {
                if (mp[next] < mp[pre]) {
                    result.push_back(i);
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}
