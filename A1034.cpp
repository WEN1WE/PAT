/*
 * 1. 对人员进行编号，方便图的处理
 * 2. 题目说的是打电话的次数，不是人数，所以人数更大
 * 3. 打电话是相互的，所以使用邻接矩阵
 * 4. int graph[MAX][MAX]; // 自动初始化为0
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2010;
map<string, int> nameToID;
map<int, string> idToName;
vector<int> weight(MAX);
int graph[MAX][MAX];
int nOfPeople = 0;
bool visited[MAX] = {false};

int getID(string & name) {
    if (nameToID.find(name) == nameToID.end()) {
        nameToID[name] = nOfPeople;
        idToName[nOfPeople] = name;
        nOfPeople++;
    }
    return nameToID[name];
}

int head = -1;
int maxWeight = 0;
int totalWeight = 0;
int members = 0;
void dfs(int v) {
    if (weight[v] > maxWeight) {
        head = v;
        maxWeight = weight[v];
    }
    totalWeight += weight[v];
    visited[v] = true;
    members++;
    
    for (int i = 0; i < nOfPeople; i++) {
        if (graph[v][i] != 0 && !visited[i]) {
            dfs(i);
        }
    }
    
}

struct Head {
    int id;
    int members = 0;
};

bool cmp (Head h1, Head h2) {
    return idToName[h1.id] < idToName[h2.id];
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<Head> result;

    for (int i = 0; i < n; i++) {
        int time, id1, id2;
        string name1, name2;
        cin >> name1 >> name2 >> time;
        id1 = getID(name1);
        id2 = getID(name2);
        weight[id1] += time;
        weight[id2] += time;
        graph[id1][id2] += time;
        graph[id2][id1] += time;
    }
    
    for (int i = 0; i < nOfPeople; i++) {
        if (!visited[i]) {
            dfs(i);
            if (totalWeight / 2 > k && members > 2) {
                result.push_back({head, members});
            }
            head = -1;
            maxWeight = 0;
            totalWeight = 0;
            members = 0;
        }
    }
    
    printf("%d\n", result.size());
    sort(result.begin(), result.end(), cmp);
    for (auto e : result) {
        printf("%s %d\n", idToName[e.id].c_str(), e.members);
    }
    return 0;
}
