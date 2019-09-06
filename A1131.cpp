/*
 * 1. 总结：哪些题目要用到深度优先搜索，哪些使用最短路径
 * 2. line[10000][10000], 会超内存
 * 3. 本问题的难点在于如何确定是否换乘
 * 4. dfs什么时候需要记录visited
 * 5. 本题visited 只记录一次dfs的访问，所以需要回退时还原
 * 6. 本题使用Dijkstra最后一组数据超时，可能由于每次都要进行Dijkstra,当数据大时，效率很低
 * 7. 多存数据，可以优化代码量
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 1000000000;
const int MAX = 10010;
vector<vector<int>> graph(MAX);
map<int, int> mp;
bool visited[MAX];
vector<int> path;
vector<int> tempPath;
int start, destination;
int minStops = INF;
int minTransfers = INF;

void dfs(int station, int stops, int transfers, int preLine) {
    if (visited[station]) {
        return;
    }
    tempPath.push_back(station);
    visited[station] = true;
    if (station == destination) {
        if (stops < minStops) {
            minStops = stops;
            path = tempPath;
            minTransfers = transfers;
        } else if (stops == minStops) {
            if (transfers < minTransfers) {
                minTransfers = transfers;
                path = tempPath;
            }
        }
        tempPath.pop_back();
        visited[station] = false;
        return;
    }

    for (auto e : graph[station]) {
        int nextLine = mp[station * 10000 + e];
        if (nextLine != preLine) {
            dfs(e, stops + 1, transfers + 1, nextLine);
        } else {
            dfs(e, stops + 1, transfers, nextLine);
        }
    }

    tempPath.pop_back();
    visited[station] = false;
}

void print() {
    int s1 = path[0];
    int s2;
    int preLine = mp[path[0] * 10000 + path[1]];
    int curLine;

    for (int i = 1; i < path.size() - 1; i++) {
        curLine = mp[path[i] * 10000 + path[i + 1]];
        if (preLine != curLine) {
            s2 = path[i];
            printf("Take Line#%d from %04d to %04d.\n", preLine, s1, s2);
            preLine = curLine;
            s1 = path[i];
        }
    }
    s2 = path[path.size() - 1];
    printf("Take Line#%d from %04d to %04d.\n", preLine, s1, s2);
}

int main() {
    int N, M, K;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int pre, cur;
        scanf("%d %d", &M, &pre);
        for (int j = 1; j < M; j++) {
            scanf("%d", &cur);
            mp[pre * 10000 + cur] = i;
            mp[cur * 10000 + pre] = i;
            graph[pre].push_back(cur);
            graph[cur].push_back(pre);
            pre = cur;
        }
    }

    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        scanf("%d %d", &start, &destination);
        dfs(start, 0, 0, -1);
        printf("%d\n", path.size() - 1);
        print();
        minStops = INF;
        minTransfers = INF;
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
const int MAX = 10010;
int dist[MAX];
bool visited[MAX];
int start, destination;
map<int, bool> mp;

void init() {
    fill(dist, dist + MAX, INF);
    fill(visited, visited + MAX, false);
}

struct Edge {
    int from;
    int to;
    int line;
};
vector<Edge> graph[MAX];
vector<Edge> parent[MAX];


int findMin() {
    int minDist = INF;
    int v = -1;
    for (auto e : mp) {
        if (!visited[e.first] && dist[e.first] < minDist) {
            minDist = dist[e.first];
            v = e.first;
        }
    }
    return v;
}

void relax(int v) {
    for (auto e : graph[v]) {
        if (!visited[e.to]) {
            if (dist[v] + 1 < dist[e.to]) {
                dist[e.to] = dist[v] + 1;
                parent[e.to].clear();
                parent[e.to].push_back(e);
            } else if (dist[v] + 1 == dist[e.to]) {
                parent[e.to].push_back(e);
            }
        }
    }
}

void Dijkstra(int s) {
    dist[s] = 0;
    
    for (int i = 0; i < MAX; i++) {
        int v = findMin();
        if (v == -1) {
            break;
        }
        visited[v] = true;
        relax(v);
    }
}

int minTransfer = INF;
vector<Edge> path;
vector<Edge> tempPath;

int getTransfer(vector<Edge> & p) {
    map<int, bool> record;
    for (auto e : p) {
        record[e.line] = true;
    }
    return record.size();
}

void dfs(int v) {
    if (v == start) {
        int transfer = getTransfer(tempPath);
        if (transfer < minTransfer) {
            path = tempPath;
            minTransfer = transfer;
        }
        return;
    }
    for (auto e : parent[v]) {
        tempPath.push_back(e);
        dfs(e.from);
        tempPath.pop_back();
    }
}

void print(vector<Edge> & p) {
    reverse(p.begin(), p.end());
    int preLine = p[0].line;
    int pre = p[0].from;
    for (int i = 1; i < p.size(); i++) {
        int curLine = p[i].line;
        if (preLine != curLine) {
            printf("Take Line#%d from %04d to %04d.\n", preLine, pre, p[i].from);
            preLine = curLine;
            pre = p[i].from;
        }
    }
    printf("Take Line#%d from %04d to %04d.\n", preLine, pre, destination);
}

int main() {
    init();
    int N, M, K;
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        int pre, cur;
        scanf("%d %d", &M, &pre);
        mp[pre] = true;
        for (int j = 1; j < M; j++) {
            scanf("%d", &cur);
            mp[cur] = true;
            graph[pre].push_back({pre, cur, i});
            graph[cur].push_back({cur, pre, i});
            pre = cur;
        }
    }
    scanf("%d", &K);
    
    for(int i = 0; i < K; i++) {
        scanf("%d %d", &start, &destination);
        Dijkstra(start);
        dfs(destination);
        printf("%d\n", path.size());
        print(path);
        minTransfer = INF;
        init();
    }
    return 0;
}
