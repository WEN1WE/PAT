/*
 * 1. 像这种双向的问题，也许使用邻接矩阵会很方便
 * 2. fill 的用法
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;
const int MAX = 510;
int n, m, C1, C2;
int graph[MAX][MAX];
int dist[MAX];
int weight[MAX];
int teamCount[MAX];
int nOfPath[MAX];
bool visited[MAX];

void Dijkstra(int s) {
    dist[s] = 0;
    teamCount[s] = weight[s];
    nOfPath[s] = 1;
    
    for (int i = 0; i < n; i++) {
        
    }
    
}

void init() {
    fill(graph[0], graph[0] + 510 * 510, INF);
    fill(dist, dist + 510, INF);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &C1, &C2);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    
    for (int i = 0; i < m; i++) {
        int c1, c2, w;
        scanf("%d %d %d", &c1, &c2, &w);
        graph[c1][c2] = w;
        graph[c2][c1] = w;
    }
    
    
}
