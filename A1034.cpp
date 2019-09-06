/*
 * 1. 对人员进行编号，方便图的处理
 * 2. 题目说的是打电话的次数，不是人数，所以人数更大
 * 3. 打电话是相互的，所以使用邻接矩阵
 * 4. int graph[MAX][MAX]; // 自动初始化为0
 * 5. 本题也可以使用union find
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

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Gang {
    int totalWeight = 0;
    int maxWeight = 0;
    int n = 0;
    string head;
};


const int MAX = 2010;
int timeRecord[MAX];
int parent[MAX];
unordered_map<string, int> nameToID;
unordered_map<int, string> idToName;
unordered_map<int, Gang> mp;

void init() {
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
    }
}

int root(int i) {
    while (i != parent[i]) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void Union(int p, int q) {
    int r1 = root(p);
    int r2 = root(q);
    if (r1 != r2) {
        parent[r1] = r2;
    }
}

bool cmp(Gang & g1, Gang & g2) {
    return g1.head < g2.head;
}

int main() {
    init();
    int N, K, cnt = 1;
    scanf("%d %d", &N, &K);
    vector<Gang> result;
    
    for (int i = 0; i < N; i++) {
        string name1, name2;
        int time, id1, id2;
        cin >> name1 >> name2 >> time;
        if (nameToID.find(name1) == nameToID.end()) {
            nameToID[name1] = cnt;
            idToName[cnt] = name1;
            cnt++;
        }
        if (nameToID.find(name2) == nameToID.end()) {
            nameToID[name2] = cnt;
            idToName[cnt] = name2;
            cnt++;
        }
        id1 = nameToID[name1];
        id2 = nameToID[name2];
        timeRecord[id1] += time;
        timeRecord[id2] += time;
        Union(id1, id2);
    }
    
    int n = nameToID.size();
    
    for (int i = 1; i <= n; i++) {
        int r = root(i);
        if (mp[r].maxWeight < timeRecord[i]) {
            mp[r].maxWeight = timeRecord[i];
            mp[r].head = idToName[i];
        }
        mp[r].totalWeight += timeRecord[i];
        mp[r].n += 1;
    }
    
    for (auto & e : mp) {
        if (e.second.n > 2 && e.second.totalWeight > 2 * K) {
            result.push_back(e.second);
        }
    }
    
    sort(result.begin(), result.end(), cmp);
    
    printf("%d\n", result.size());
    for (auto & e : result) {
        printf("%s %d\n", e.head.c_str(), e.n);
    }
    
    return 0;
}
