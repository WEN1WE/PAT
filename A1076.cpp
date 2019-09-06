/*
 * 1. 思考: 广度优先搜索如何确定层次 : 每个节点记录一个层次信息
 * 2. 本题使用深度优先搜索很容易出处，因为可能有环，影响转发的顺序
 * 3. 广度优先搜索最主要是确定什么时候进入队列
 * 4. 进入队列是，一定要注意加标记的时间，不是出队列加标记，是入队列加标记
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int id = 0;
    int level = 0;
};
vector<vector<Node>> graph;
int L, cnt = 0;

void bfs(Node node, vector<bool> & visited) {
    queue<Node> q;
    q.push(node);
    visited[node.id] = true;
    
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        for (auto e : graph[current.id]) {
            if (!visited[e.id]) {
                visited[e.id] = true;
                e.level = current.level + 1;
                if (e.level <= L) {
                    q.push(e);
                    cnt++;
                }
            }
        }
    }
}


int main() {
    int n;
    scanf("%d %d", &n, &L);
    graph.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        int m, id;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &id);
            graph[id].push_back({i, 0});
        }
    }
    
    int k, userID;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &userID) ;
        vector<bool> visited(n + 1);
        bfs({userID, 0}, visited);
        cout << cnt << endl;
        cnt = 0;
    }
     
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L;
const int MAX = 1010;
vector<vector<int>> graph(MAX);
int visited[MAX];
int cnt = 0;

struct User {
    int id;
    int level;
};

void bfs(int id) {
    queue<User> q;
    q.push({id, 0});
    visited[id] = true;
    
    while (!q.empty()) {
        User user = q.front();
        cnt++;
        q.pop();
        
        for (auto e : graph[user.id]) {
            if (!visited[e] && user.level < L) {
                q.push({e, user.level + 1});
                visited[e] = true;
            }
        }
    }
}

int main() {
    int M, K, id;
    scanf("%d %d", &N, &L);
    graph.resize(N + 1);
    
    if (N == 1) {
        printf("0\n");
        return 0;
    }
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &id);
            graph[id].push_back(i);
        }
    }
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &id);
        bfs(id);
        printf("%d\n", cnt - 1);
        cnt = 0;
        fill(visited, visited + MAX, false);
    }
    
    return 0;
}
