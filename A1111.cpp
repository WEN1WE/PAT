/*
 * 1. 本题的特点是使用两次Dijkstra.
 */

#include <iostream>
#include <vector>
using namespace std;

int N, M, S, D;
const int INF = 1000000000;
const int MAX = 510;
int graphDistance[MAX][MAX];
int graphTime[MAX][MAX];
int visited[MAX];
int dist[MAX];
int Time[MAX];
vector<vector<int>> fatherD(MAX);
vector<vector<int>> fatheT(MAX);

void init() {
    fill(graphDistance[0], graphDistance[0] + MAX * MAX, INF);
    fill(graphTime[0], graphTime[0] + MAX * MAX, INF);
    fill(dist, dist + MAX, INF);
    fill(Time, Time + MAX, INF);
}

int findMin(int record[]) {
    int v = -1;
    int least = INF;
    
    for (int w = 0; w < N; w++) {
        if (!visited[w] && record[w] < least) {
            v = w;
            least = record[w];
        }
    }
    return v;
}

void relax(int v, int graph[][MAX], int record[], vector<vector<int>> & father) {
    for (int w = 0; w < N; w++) {
        if (!visited[w] && graph[v][w] != INF) {
            if (record[v] + graph[v][w] < record[w]) {
                record[w] = record[v] + graph[v][w];
                father[w].clear();
                father[w].push_back(v);
            } else if (record[v] + graph[v][w] == record[w]) {
                father[w].push_back(v);
            }
        }
    }
}

void Dijkstra(int graph[][MAX], int record[], vector<vector<int>> & father) { 
    record[S] = 0;
    
    for (int i = 0; i < N; i++) {
        int v = findMin(record);
        if (v == -1) {
            break;
        }
        visited[v] = true;
        relax(v, graph, record, father);
    }
}

vector<int> pathS;
vector<int> pathT;
vector<int> tempPath;
int leastTime = INF;
int leastCnt = INF;
void dfsS(int v, int totalTime) {
    if (v == S) {
        tempPath.push_back(S);
        if (totalTime < leastTime) {
            pathS = tempPath;
            leastTime = totalTime;
        }
        tempPath.pop_back();
        return;
    } 
    tempPath.push_back(v);
    for (auto e : fatherD[v]) {
        dfsS(e, totalTime + graphTime[e][v]);
    }
    tempPath.pop_back();
}

void dfsT(int v, int cnt) {
    if (v == S) {
        tempPath.push_back(S);
        if (cnt < leastCnt) {
            pathT = tempPath;
            leastCnt = cnt;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (auto e : fatheT[v]) {
        dfsT(e, cnt + 1);
    }
    tempPath.pop_back();
}

void print(vector<int> & path) {
    for (int i = path.size() - 1; i >= 0; i--) {
        if (i != path.size() - 1) {
            printf(" -> ");
        }
        printf("%d", path[i]);
    }
    printf("\n");
}

int main() {
    init();
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int v1, v2, oneWay, length, time;
        scanf("%d %d %d %d %d", &v1, &v2, &oneWay, &length, &time);
        graphDistance[v1][v2] = length;
        graphTime[v1][v2] = time;
        if (oneWay == 0) {
            graphDistance[v2][v1] = length;
            graphTime[v2][v1] = time;
        }
    }
    scanf("%d %d", &S, &D);
    Dijkstra(graphDistance, dist, fatherD);
    fill(visited, visited + MAX, false);
    Dijkstra(graphTime, Time, fatheT);
    dfsS(D, 0);
    dfsT(D, 0);
    
    if (pathS != pathT) {
        printf("Distance = %d: ", dist[D]);
        print(pathS);
        printf("Time = %d: ", Time[D]);
        print(pathT);
    } else {
        printf("Distance = %d; Time = %d: ", dist[D], Time[D]);
        print(pathS);
    }
    return 0;
}
