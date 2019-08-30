/*
 * 1. 本题不能只用Dijkstra, 要把最短路径求出来后用DFS
 * 2. 按照自己的写法出错的原因，后面出现的站点不能给前面的站点补给
 * 3. 再次学习 dfs 遇到分叉的时候应该怎么做
 */

#include <iostream>
#include <vector>
using namespace std;

int Cmax, N, Sp, M, halfFull;
const int INF = 1000000000;
const int MAX = 510;
int graph[MAX][MAX];
int dist[MAX];
int weight[MAX];
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

int leastSent = INF;
int leastBack = INF;
vector<int> path;
vector<int> tempPath;
void dfs(int v) {
    if (v == 0) {
        int sent = 0; 
        int remain = 0;
        int need = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--) {
            need = halfFull - weight[tempPath[i]];
            if (need <= 0) {
                remain += -need;
            } else {
                if (remain >= need) {
                    remain -= need;
                } else {
                    sent += need - remain;
                    remain = 0;
                }
            }
        }
        
        if (sent < leastSent) {
            leastSent = sent;
            leastBack = remain;
            path = tempPath;
        } else if (sent == leastSent) {
            if (remain < leastBack) {
                leastBack = remain;
                path = tempPath;
            }
        }
        return;
    }
    tempPath.push_back(v);
    for (auto e : father[v]) {
        dfs(e);
    }
    tempPath.pop_back();
}

int main() {
    init();
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    halfFull = Cmax / 2;
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
    dfs(Sp);
    
    printf("%d 0", leastSent);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("->%d", path[i]);
    }
    printf(" %d", leastBack);
    return 0;
}
