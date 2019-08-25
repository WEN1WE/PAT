/*
 * 1. 思考: 广度优先搜索如何确定层次 : 每个节点记录一个层次信息
 * 2. 本题使用深度优先搜索很容易出处，因为可能有环，影响转发的顺序
 * 3. 广度优先搜索最主要是确定什么时候进入队列
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
