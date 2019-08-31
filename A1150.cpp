/*
 * 1. 通过map来去重
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int INF = 1000000000;
const int MAX = 210;
int graph[MAX][MAX];

void init() {
    fill(graph[0], graph[0] + MAX * MAX, MAX);
}

int main() {
    init();
    int N, M, K;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int city1, city2, dist;
        scanf("%d %d %d", &city1, &city2, &dist);
        graph[city1][city2] = dist;
        graph[city2][city1] = dist;
    }
    
    scanf("%d", &K);
    int shortest = INF;
    int id = 0;
    for (int i = 1; i <= K; i++) {
        int n, city;
        vector<int> path;
        map<int, bool> mp;

        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &city);
            path.push_back(city);
        }
        
        int pre = path[0];
        int totalDist = 0;
        int flag = true;
        for (int j = 1; j < path.size(); j++) {
            mp[pre] = true;
            int cur = path[j];
            if (graph[pre][cur] == MAX) {
                flag = false;
                break;
            }
            totalDist += graph[pre][cur];
            pre = cur;
        }
        
        if (!flag) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        } else if (path[0] != path[path.size() - 1] || mp.size() < N) {
            printf("Path %d: %d (Not a TS cycle)\n", i, totalDist);
        } else if (mp.size() == N){
            if (path.size() == N + 1)
                printf("Path %d: %d (TS simple cycle)\n", i, totalDist);
            else
                printf("Path %d: %d (TS cycle)\n", i, totalDist);
            
            if (totalDist < shortest) {
                shortest = totalDist;
                id = i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", id, shortest);
    return 0;
}
