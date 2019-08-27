/*
 * 1. 像这种双向的问题，也许使用邻接矩阵会很方便
 * 2. fill 的用法
 * 3. 数有多少条路径很有技巧
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
int teamRecord[MAX];
int teamCount[MAX];
int nOfPath[MAX];
bool visited[MAX];

int findMin() {
    int v = -1;
    int minDist = INF;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && minDist > dist[i]) {
            minDist = dist[i];
            v = i;
        }
    }
    return v;
}

void relax(int v) {
    for (int w = 0; w < n; w++) {
        if (visited[w] || graph[v][w] == INF) {
            continue;
        }
        if (dist[v] + graph[v][w] < dist[w]) {
            nOfPath[w] = nOfPath[v];
            teamCount[w] = teamCount[v] + teamRecord[w];
            dist[w] = dist[v] + graph[v][w];
        } else if (dist[v] + graph[v][w] == dist[w]) {
            nOfPath[w] += nOfPath[v];
            teamCount[w] = max(teamCount[w], teamCount[v] + teamRecord[w]);
        }
    }
}

void Dijkstra(int s) {
    dist[s] = 0;
    teamCount[s] = teamRecord[s];
    nOfPath[s] = 1;

    for (int i = 0; i < n; i++) {
        int v = findMin();
        if (v == -1) {
            break;
        }
        visited[v] = true;
        relax(v);
    }
}

void init() {
    fill(graph[0], graph[0] + 510 * 510, INF);
    fill(dist, dist + 510, INF);
}

int main() {
    init();
    scanf("%d %d %d %d", &n, &m, &C1, &C2);

    for (int i = 0; i < n; i++) {
        scanf("%d", &teamRecord[i]);
    }

    for (int i = 0; i < m; i++) {
        int c1, c2, w;
        scanf("%d %d %d", &c1, &c2, &w);
        graph[c1][c2] = w;
        graph[c2][c1] = w;
    }
    Dijkstra(C1);
    cout << nOfPath[C2] << " " << teamCount[C2] << endl;
}
