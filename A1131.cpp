/*
 * 1. 总结：哪些题目要用到深度优先搜索，哪些使用最短路径
 * 2. line[10000][10000], 会超内存
 * 3. 本问题的难点在于如何确定是否换乘
 * 4. dfs什么时候需要记录visited
 * 5. 本题visited 只记录一次dfs的访问，所以需要回退时还原
 */

#include <iostream> 
#include <vector>
#include <map>
using namespace std;

int start, destination;
const int MAX = 10000;
vector<int> adjoin[MAX];
int visited[MAX];
map<int, int> mp;

vector<int> path;
vector<int> tempPath;
int minStop = MAX;
int minTransfer = MAX;

int transfer() {
    int preLine, nextLine, curStop, cnt = 0;
    preLine = mp[tempPath[0] * MAX + tempPath[1]];
    curStop = tempPath[1];
    for (int i = 2; i < tempPath.size(); i++) {
        nextLine = mp[curStop * MAX + tempPath[i]];
        if (preLine != nextLine) {
            cnt++;
        }
        curStop = tempPath[i];
        preLine = nextLine;
    }
    return cnt;
}

void dfs(int v, int cntStop) {
    visited[v] = true;
    tempPath.push_back(v);
    if (v == destination) {
        if (cntStop < minStop) {
            path = tempPath;
            minStop = cntStop;
            minTransfer = transfer();
        } else if (cntStop == minStop) {
            int cntTransfer = transfer();
            if (cntTransfer < minTransfer) {
                path = tempPath;
                minTransfer = cntTransfer;
            }
        }
        visited[v] = false;
        tempPath.pop_back();
        return;
    }
    
    for (auto e : adjoin[v]) {
        if (!visited[e])
            dfs(e, cntStop + 1);
    }
    visited[v] = false;
    tempPath.pop_back();
}

void print() {
    int begin, end;
    int preLine, nextLine, curStop;
    begin = path[0];
    preLine = mp[path[0] * MAX + path[1]];
    curStop = path[1];
    for (int i = 2; i < path.size(); i++) {
        nextLine = mp[curStop * MAX + path[i]];
        if (preLine != nextLine) {
            end = curStop;
            printf("Take Line#%d from %04d to %04d.\n", preLine, begin, end);
            begin = end;
        }
        curStop = path[i];
        preLine = nextLine;
    }
    printf("Take Line#%d from %04d to %04d.\n", preLine, begin, destination);
}

int main() {
    int N, M, K;
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        int pre, cur;
        scanf("%d %d", &M, &pre);
        for (int j = 1; j < M; j++) {
            scanf("%d", &cur);
            mp[pre * MAX + cur] = i;
            mp[cur * MAX + pre] = i;
            adjoin[pre].push_back(cur);
            adjoin[cur].push_back(pre);
            pre = cur;
        }
    }
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &start, &destination);
        dfs(start, 0);
        printf("%d\n", minStop);
        print();
        minStop = MAX;
        minTransfer = MAX;
    }
    return 0;
}
