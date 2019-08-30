#include <iostream>
#include <vector>
using namespace std;

int N, M, K, D;
const int INF = 1000000000;
const int MAX = 1020;
int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

void init() {
    fill(graph[0], graph[0] + MAX * MAX, INF);
    fill(dist, dist + MAX, INF);
}

int toID(string & s) {
    int id;
    if (s[0] == 'G') {
        s = s.substr(1);
        id = stoi(s) + N;
    } else {
        id = stoi(s);
    }
    return id;
}

int findMin() {
    int v = -1;
    int minDist = INF;
    
    for (int w = 1; w <= N + M; w++) {
        if (!visited[w] && dist[w] < minDist) {
            minDist = dist[w];
            v = w;
        }
    }
    return v;
}

void relax(int v) {
    for (int w = 1; w <= N + M; w++) {
        if (!visited[w] && graph[v][w] != INF) {
            if (dist[v] + graph[v][w] < dist[w]) {
                dist[w] = dist[v] + graph[v][w];
            }
        }
    }
}

void Dijkstra(int s) {
    dist[s] = 0;
    
    for (int i = 1; i <= N + M; i++) {
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
    scanf("%d %d %d %d", &N, &M, &K, &D);

    for (int i = 0; i < K; i++) {
        int d, id1, id2;
        string p1, p2;
        cin >> p1 >> p2 >> d;
        id1 = toID(p1);
        id2 = toID(p2);
        graph[id1][id2] = d;
        graph[id2][id1] = d;
    }
    
    int minDist = -1;
    int gasStation = 0;
    int totalDist = INF;
    double avgDist;
    for (int i = N + 1; i <= N + M; i++) {
        int tempMin = INF;
        double tempTotal = 0;
        Dijkstra(i);
        for (int j = 1; j <= N; j++) {
            if (dist[j] < tempMin) {
                tempMin = dist[j];
            }
            tempTotal += dist[j];
        }
        if (tempMin > minDist) {
            gasStation = i;
            minDist = tempMin;
            totalDist = tempTotal;
        } else if (tempMin == minDist) {
            if (tempTotal < totalDist) {
                gasStation = i;
                totalDist = tempTotal;
            }
        }
    }
    avgDist = totalDist * 1.0 / N;
    printf("G%d\n", gasStation - N);
    printf("%.1f %.1f", minDist * 1.0, avgDist);
    return 0;
}
