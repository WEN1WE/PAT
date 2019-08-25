/*
 * 1. 思考如何收集数据，与图的深度优先搜索联系
 * 2. 思考，本题也可以使用union find;
 */


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 10000;
struct Person {
    int set = 0;
    int area = 0;
    vector<int> family;
};

struct Family {
    int id;
    int members;
    double avgSets;
    double avgArea;
};

int totalSets = 0;
int totalArea = 0;
int totalMembers = 0;
int smallest = 10000;
vector<bool> visited(MAX);
vector<Person> graph(MAX);

void dfs(int id) {
    if (!visited[id]) {
        if (id < smallest) {
            smallest = id;
        }
        totalArea += graph[id].area;
        totalSets += graph[id].set;
        totalMembers++;
        visited[id] = true;
        
        for (auto e : graph[id].family) {
            dfs(e);
        }
    }
}

bool cmp(Family f1, Family f2) {
    return f1.avgArea == f2.avgArea ? f1.id < f2.id : f1.avgArea > f2.avgArea;
}

int main() {
    int n;
    scanf("%d", &n);
    map<int, bool> mp;
    vector<Family> result;
    
    for (int i = 0; i < n; i++) {
        int id, father, mother, k, child, set, area;
        scanf("%d %d %d %d", &id, &father, &mother, &k);
        mp[id] = true;
        if (father != -1) {
            mp[father] = true;
            graph[id].family.push_back(father);
            graph[father].family.push_back(id);
        }
        if (mother != -1) {
            mp[mother] = true;
            graph[id].family.push_back(mother);
            graph[mother].family.push_back(id);
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            graph[id].family.push_back(child);
            graph[child].family.push_back(id);
            mp[child] = true;
        }
        scanf("%d %d", &set, &area);
        graph[id].set = set;
        graph[id].area = area;
    }
    
    for (auto e : mp) {
        dfs(e.first);
        if (smallest != 10000) {
            result.push_back({smallest, totalMembers, totalSets * 1.0 / totalMembers, totalArea * 1.0 / totalMembers});
        }
        totalSets = 0;
        totalArea = 0;
        totalMembers = 0;
        smallest = 10000;
    }
    sort(result.begin(), result.end(), cmp);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        printf("%04d %d %.3f %.3f\n", result[i].id, result[i].members, result[i].avgSets, result[i].avgArea);
    }
}
