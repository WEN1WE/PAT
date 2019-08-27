/*
 * 1. 思考，快速将图的信息存储
 * 2. bool table[10000][10000]; // 这个太大
 * 3. 注意 按照4位数字打印
 * 4. 注意-0000的性别问题
 * 5. 可以使用结构体保存性别
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Pair {
    int id1;
    int id2;
};

vector<vector<int>> graph(10000);
vector<Pair> result;
vector<bool> gender(10000);

bool isFriend (int id1, int id2) {
    for (auto e : graph[abs(id1)]) {
        if (e == id2) {
            return true;
        }
    }
    return false;
}

void find(int id1, int id2) {
    for (auto friend1 : graph[id1]) {
        if (gender[friend1] == gender[id1] && friend1 != id2) {
            for (auto friend2 : graph[abs(id2)]) {
                if (gender[friend2] == gender[id2] && friend2 != id1) {
                    if (isFriend(friend1, friend2)) {
                        result.push_back({friend1, friend2});
                    }
                }
            }
        }
    }
}

bool cmp(Pair p1, Pair p2) {
    return p1.id1 == p2.id1 ? p1.id2 < p2.id2 : p1.id1 < p2.id1;
}

int toId(string & s) {
    if (s[0] == '-') {
        s = s.substr(1);
    } else {
        gender[stoi(s)] = true;
    }
    return stoi(s);
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int id1, id2;
        string s1, s2;
        cin >> s1 >> s2;
        id1 = toId(s1);
        id2 = toId(s2);
        
        graph[id1].push_back(id2);
        graph[id2].push_back(id1);
    }
    
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int id1, id2;
        cin >> id1 >> id2;
        id1 = abs(id1);
        id2 = abs(id2);
        
        find(id1, id2);
        printf("%d\n", result.size());
        sort(result.begin(), result.end(), cmp);
        for (auto e : result) {
            printf("%04d %04d\n", e.id1, e.id2);
        }
        result.clear();
    }
    return 0;
}
