/*
 * 1. 由于最后要根据平均happiness比较， 所以最后还是要用到 DFS
 * 2. 可以将最好找路径放在DFS里面做，也可以在Dijkstra里面做一部分
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
const int MAX = 210;
const int INF = 1000000000;
int graph[MAX][MAX];
int weight[MAX];
int totalWeight[MAX];
int dist[MAX];
vector<int> father[MAX];
bool visited[MAX];
int nOfPath[MAX];
vector<int> path;
vector<int> tempPath;

void init() {
    fill(graph[0], graph[0] + MAX * MAX, INF);
    fill(dist, dist + MAX, INF);
}

int findMin() {
    int v = -1;
    int smallest = INF;
    
    for (int w = 0; w < N; w++) {
        if (!visited[w] && dist[w] < smallest) {
            smallest = dist[w];
            v = w;
        }
    }
    return v;
}

void relax(int v) {
    for (int w = 0; w < N; w++) {
        if (!visited[w]) {
            if (dist[v] + graph[v][w] < dist[w]) {
                dist[w] = dist[v] + graph[v][w];
                nOfPath[w] = nOfPath[v];
                
                totalWeight[w] = weight[w] + totalWeight[v];
                father[w].clear();
                father[w].push_back(v);
            } else if (dist[v] + graph[v][w] == dist[w]) {
                nOfPath[w] += nOfPath[v];
                
                if (totalWeight[v] + weight[w] > totalWeight[w]) {
                    totalWeight[w] = totalWeight[v] + weight[w];
                    father[w].clear();
                    father[w].push_back(v);
                } else if (totalWeight[v] + weight[w] == totalWeight[w]) {
                    father[w].push_back(v);
                }
            }
        }
    }
}

void Dijkstra(int s) {
    nOfPath[s] = 1;
    dist[s] = 0;
    totalWeight[s] = 0;
    
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
int maxHappiness = -1;
void dfs(int v, int happiness, int count) {
    tempPath.push_back(v);
    if (v == 0) {
        if (happiness / count > maxHappiness) {
            totalHappiness = happiness;
            path = tempPath;
            maxHappiness = happiness / count;
        }
        tempPath.clear();
        return;
    }
    for (auto e : father[v]) {
        dfs(e, weight[v] + happiness, ++count);
    }
}

int main() {
    init();
    string start;
    cin >> N >> K >> start;
    map<string, int> nameToID;
    map<int, string> idToName;
    nameToID[start] = 0;
    idToName[0] = start;
    
    for (int i = 1; i < N; i++) {
        int h;
        string name;
        cin >> name >> h;
        nameToID[name] = i;
        idToName[i] = name;
        weight[i] = h;
    }
    
    for (int i = 0; i < K; i++) {
        int cost, id1, id2;
        string c1, c2;
        cin >> c1 >> c2 >> cost;
        id1 = nameToID[c1];
        id2 = nameToID[c2];
        graph[id1][id2] = cost;
        graph[id2][id1] = cost;
    }
    
    int idROM = nameToID["ROM"];
    Dijkstra(nameToID[start]);
    dfs(idROM, 0, 0);
    reverse(path.begin(), path.end());
    printf("%d %d %d %d\n", nOfPath[idROM], dist[idROM], totalHappiness, maxHappiness);
    for (int i = 0; i < path.size(); i++) {
        if (i != 0) {
            printf("->");
        }
        printf("%s", idToName[path[i]].c_str());
    }
    printf("\n");
    return 0;
}
