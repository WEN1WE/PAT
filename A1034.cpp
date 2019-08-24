/*
 * 1. 对人员进行编号，方便图的处理
 * 2. 题目说的是打电话的次数，不是人数，所以人数更大
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX = 2010;
map<string, int> nameToID;
map<int, string> idToName;
vector<int> weight(MAX);
int graph[MAX][MAX] = {0};
int nOfPeople = 0;

int getID(string & name) {
    if (nameToID.find(name) == nameToID.end()) {
        nameToID[name] = nOfPeople;
        idToName[nOfPeople] = name;
        nOfPeople++;
    }
    return nameToID[name];
}

int main() {
    int n, k;
    cin >> n >> k;
    
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
}
