#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, S, D;
const int MAX = 510;
const int INF = 1000000000;
struct Highway {
    int distance = INF;
    int cost = INF;
};
Highway graph[MAX][MAX];
int dist[MAX];
int cost[MAX];
int visited[MAX];
int father[MAX];

void init() {
    fill(dist, dist + MAX, INF);
    fill(cost, cost + MAX, INF);
}

int findMin() {
    int minDist = INF;
    int v = -1;
    
    for (int w = 0; w < N; w++) {
        if (!visited[w] && dist[w] < minDist) {
            v = w;
            minDist = dist[w];
        }
    }
    return v;
}

void relax(int v) {
    for (int w = 0; w < N; w++) {
        if (!visited[w] && graph[v][w].distance != INF) {
            if (dist[v] + graph[v][w].distance < dist[w]) {
                dist[w] = dist[v] + graph[v][w].distance;
                cost[w] = cost[v] + graph[v][w].cost;
                father[w] = v;
            } else if (dist[v] + graph[v][w].distance == dist[w]) {
                if (cost[v] + graph[v][w].cost < cost[w]) {
                    cost[w] = cost[v] + graph[v][w].cost;
                    father[w] = v;
                }
            }
        }
    }
}

void Dijkstra(int s) {
    dist[s] = 0;
    cost[s] = 0;
    
    for (int i = 0; i < N; i++) {
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
    
    scanf("%d %d %d %d", &N, &M, &S, &D);
    
    for (int i = 0; i < M; i++) {
        int c1, c2, d, cost;
        scanf("%d %d %d %d", &c1, &c2, &d, &cost);
        graph[c1][c2] = {d, cost};
        graph[c2][c1] = {d, cost};
    }
    Dijkstra(0);
    
    vector<int> path;
    int current = D;
    while (true) {
        path.push_back(current);
        if (current == S) {
            break;
        }
        current = father[current];
        
    }
    reverse(path.begin(), path.end());
    
    for (int i = 0; i < path.size(); i++) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", dist[D], cost[D]);
    return 0;
}
