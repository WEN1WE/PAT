/*
 * 1. 本题不能只用Dijkstra, 要把最短路径求出来后用DFS
 */

#include <iostream>
#include <vector>
using namespace std;

int Cmax, N, Sp, M;
const int INF = 1000000000;
const int MAX = 510;
int graph[MAX][MAX];
int dist[MAX];
int weight[MAX];
int bikeCount[MAX];
bool visited[MAX];
vector<vector<int>> father(MAX);


void init() {
    fill(graph[0], graph[0] + MAX * MAX, INF);
    fill(dist, dist + MAX, INF);
}

int findMin() {
    int minDist = INF;
    int v = -1;
    for (int i = 0; i <= N; i++) {
        if (!visited[i] && dist[i] < minDist) {
            v = i;
            minDist = dist[i];
        }
    }
    return v;
}

void relax(int v) {
    for (int w = 0; w <= N; w++) {
        if (!visited[w] && graph[v][w] != INF) {
            if (dist[v] + graph[v][w] < dist[w]) {
                dist[w] = dist[v] + graph[v][w];
                father[w].clear();
                father[w].push_back(v);
            } else if (dist[v] + graph[v][w] == dist[w]) {
                father[w].push_back(v);
            }
        }
    }
}

void Dijkstra(int s) {
    dist[s] = 0;
    
    for (int i = 0; i <= N; i++) {
        int v = findMin();
        if (v == -1) {
            break;
        }
        visited[v] = true;
        relax(v);
    }
}

int main() {
    init();
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &weight[i]);
    }
    
    for (int i = 0; i < M; i++) {
        int v, w, len;
        scanf("%d %d %d", &v, &w, &len);
        graph[v][w] = len;
        graph[w][v] = len;
    }
    Dijkstra(0);
}
