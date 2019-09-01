/*
 * 1. 本题使用三维数组比较方便
 * 2. 题目最后时 > T, 不是2
 * 3. 若使用深度优先搜索，会使深度太大
 * 4. 进队列的时候，进行标记，而不是出队列的时候
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x;
    int y;
    int z;
};

int m, n, L;
int cnt = 0;
int totalVolume = 0;
queue<Point> q;
vector<vector<vector<bool>>> graph;
vector<vector<vector<bool>>> hashTable;
bool reasonable(int x, int y, int z) {
    return  x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < L && graph[z][y][x] && !hashTable[z][y][x];
}

void build(vector<vector<vector<bool>>> & table) {
    table.resize(L);
    for (auto & e1 : table) {
        e1.resize(m);
        for (auto & e2 : e1) {
            e2.resize(n);
        }
    }
}

void toQueue(int x, int y, int z) {
    if (reasonable(x, y, z)) {
        q.push({x, y, z});
        hashTable[z][y][x] = true;
        cnt++;
    }
}

void bfs(int x, int y, int z) {
    toQueue(x, y, z);
    while (!q.empty()) {
        Point point = q.front();
        toQueue(point.x - 1, point.y, point.z);
        toQueue(point.x + 1, point.y, point.z);
        toQueue(point.x, point.y - 1, point.z);
        toQueue(point.x, point.y + 1, point.z);
        toQueue(point.x, point.y, point.z - 1);
        toQueue(point.x, point.y, point.z + 1);
        q.pop();
    }
}

int main() {
    int T, value;
    scanf("%d %d %d %d", &m, &n, &L, &T);
    build(graph);
    build(hashTable);

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &value);
                graph[i][j][k] = value;
            }
        }
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if(reasonable(k, j, i)) {
                    bfs(k, j, i);
                    if (cnt >= T) {
                        totalVolume += cnt;
                    }
                    cnt = 0;
                }
            }
        }
    }
    cout << totalVolume;

    return 0;
}


#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int z;
    int y;
    int x;
};

int M, N, L, T;
bool graph[65][1300][130];
bool visited[65][1300][130];
queue<Point> q;
int cnt;

void toQueue(int z, int y, int x) {
    if (z >= 0 && z < L && y >= 0 && y < M && x >= 0 && x < N && !visited[z][y][x] && graph[z][y][x]) {
        visited[z][y][x] = true;
        q.push({z, y, x});
        cnt++;
    }
}

void bfs(int z, int y, int x) {
    toQueue(z, y, x);
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        toQueue(p.z + 1, p.y, p.x);
        toQueue(p.z - 1, p.y, p.x);
        toQueue(p.z, p.y + 1, p.x);
        toQueue(p.z, p.y - 1, p.x);
        toQueue(p.z, p.y, p.x + 1);
        toQueue(p.z, p.y, p.x - 1);
    }
}

int main() {
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &graph[i][j][k]);
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                bfs(i, j, k);
                if (cnt >= T) {
                    total += cnt;
                }
                cnt = 0;
            }
        }
    }
    printf("%d\n", total);
    return 0;
}
