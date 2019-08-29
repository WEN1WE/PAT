/*
 * 1. 没有二维结构体
 * 2. 在共用的变量中，不能distance 命名
 * 3. 在Dijkstra 的时候，做了两次选择
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, S, D;
const int INF = 1000000000;
const int MAX = 510;

int graphDistance[MAX][MAX];
int graphCost[MAX][MAX];
int dist[MAX];
int visited[MAX];
int father[MAX];
int totalCost[MAX];

void init() {
    fill(graphDistance[0], graphDistance[0] + MAX * MAX, INF);
    fill(graphCost[0], graphCost[0] + MAX * MAX, INF);
    fill(dist, dist + MAX, INF);
    fill(totalCost, totalCost + MAX, INF);
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
        if (!visited[w] && graphDistance[v][w] != INF) {
            if (dist[v] + graphDistance[v][w] < dist[w]) {
                dist[w] = dist[v] + graphDistance[v][w];
                totalCost[w] = totalCost[v] + graphCost[v][w];
                father[w] = v;
            } else if (dist[v] + graphDistance[v][w] == dist[w]) {
                if (totalCost[v] + graphCost[v][w] < totalCost[w]) {
                    totalCost[w] = totalCost[v] + graphCost[v][w];
                    father[w] = v;
                }
            }
        }
    }
}

void Dijkstra(int s) {
    dist[s] = 0;
    totalCost[s] = 0;
    
    for (int i = 0; i < N; i++) {
        int v = findMin();
        if (v == -1) {
            break;
        }
        visited[v] = true;
        relax(v);
    }
}

vector<int> path;
void DFS(int v) {
    if (v == S) {
        path.push_back(v);
        return;
    }
    DFS(father[v]);
    path.push_back(v);
}

int main() {
    init();
    scanf("%d %d %d %d", &N, &M, &S, &D);

    for (int i = 0; i < M; i++) {
        int c1, c2, d, cost;
        scanf("%d %d %d %d", &c1, &c2, &d, &cost);
        graphDistance[c1][c2] = d;
        graphDistance[c2][c1] = d;
        graphCost[c1][c2] = cost;
        graphCost[c2][c1] = cost;
    }
    Dijkstra(S);
    DFS(D);
    for (auto e : path) {
        printf("%d ", e);
    }
    printf("%d %d\n", dist[D], totalCost[D]);
    return 0;
}
