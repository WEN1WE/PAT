/*
 * 1. 由于最后要根据平均happiness比较， 所以最后还是要用到 DFS
 * 2. 可以将最好找路径放在DFS里面做，也可以在Dijkstra里面做一部分
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, K;
const int MAX = 210;
const int INF = 1000000000;
int graph[MAX][MAX];
int weight[MAX];
int happiness[MAX];
int dist[MAX];
int nOfPath[MAX];
vector<int> parent[MAX];
bool visited[MAX];

void init() {
    fill(graph[0], graph[0] + MAX * MAX, INF);
    fill(dist, dist + MAX, INF);
}

int findMin() {
    int minDist = INF;
    int v = -1;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            v = i;
        }
    }
    return v;
}

void relax(int v) {
    for (int w = 0; w < N; w++) {
        if (!visited[w] && graph[w][v] != INF) {
            if (dist[v] + graph[v][w] < dist[w]) {
                dist[w] = dist[v] + graph[v][w];
                nOfPath[w] = nOfPath[v];
                
                parent[w].clear();
                parent[w].push_back(v);
                happiness[w] = happiness[v] + weight[w];
            } else if (dist[v] + graph[v][w] == dist[w]) {
                nOfPath[w] += nOfPath[v];
                
                if (happiness[v] + weight[w] > happiness[w]) {
                    happiness[w] = happiness[v] + weight[w];
                    parent[w].clear();
                    parent[w].push_back(v);
                } else if (happiness[v] + weight[w] == happiness[w]) {
                    parent[w].push_back(v);
                }
            }
        }
    }
}

void Dijkstra(int s) {
    nOfPath[s] = 1;
    dist[s] = 0;
    happiness[s] = 0;
    
    for (int i = 0; i < N; i++) {
        int v = findMin();
        if (v == -1) {
            break;
        }
        visited[v] = true;
        relax(v);
    }
}

int totalHappiness = 0;
int maxAvg = -1;
vector<int> path;
vector<int> tempPath;
void dfs(int v, int total, int cnt) {
    tempPath.push_back(v);
    if (v == 0) {
        int avg = total / cnt;
        if (avg > maxAvg) {
            maxAvg = avg;
            totalHappiness = total;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    
    for (auto e : parent[v]) {
        dfs(e, weight[v] + total, cnt + 1);
    }
    tempPath.pop_back();
}

int main() {
    init();
    unordered_map<string, int> nameToID;
    unordered_map<int, string> idToName;
    string start;
    scanf("%d %d", &N, &K);
    cin >> start;
    nameToID[start] = 0;
    idToName[0] = start;
    
    for (int i = 1; i < N; i++) {
        int h;
        string city;
        cin >> city >> h;
        nameToID[city] = i;
        idToName[i] = city;
        weight[i] = h;
    }
    
    for (int i = 0; i < K; i++) {
        string city1, city2;
        int cost, id1, id2;
        cin >> city1 >> city2 >> cost;
        id1 = nameToID[city1];
        id2 = nameToID[city2];
        graph[id1][id2] = cost;
        graph[id2][id1] = cost;
    }
    
    int idROM = nameToID["ROM"];
    Dijkstra(0);
    Dijkstra(nameToID[start]);
    dfs(idROM, 0, 0);
    reverse(path.begin(), path.end());
    printf("%d %d %d %d\n", nOfPath[idROM], dist[idROM], totalHappiness, maxAvg);
    for (int i = 0; i < path.size(); i++) {
        if (i != 0) {
            printf("->");
        }
        printf("%s", idToName[path[i]].c_str());
    }
    printf("\n");
    return 0;
}
