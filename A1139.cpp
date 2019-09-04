/*
 * 1. 思考，快速将图的信息存储
 * 2. bool table[10000][10000]; // 这个太大
 * 3. 注意 按照4位数字打印
 * 4. 注意-0000的性别问题
 * 5. 可以使用结构体保存性别
 * 6. 使用map, 就少写一次循环
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


#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 10000;
vector<bool> gender(MAX);
map<int, map<int, bool>> graph;

int toID(string & s) {
    int id;
    if (s[0] == '-') {
        s = s.substr(1);
        id = stoi(s);
        gender[id] = true;
    } else {
        id = stoi(s);
    }
    return id;
}

struct Pair {
    int id1;
    int id2;
};
vector<Pair> result;

void find(int id1, int id2) {
    int friend1, friend2;
    for (auto f1 : graph[id1]) {
        friend1 = f1.first;
        if (gender[friend1] == gender[id1] && friend1 != id2) {
            for (auto f2 : graph[id2]) {
                friend2 = f2.first;
                if (gender[friend2] == gender[id2] && friend2!= id1) {
                    if (graph[friend1].find(friend2) != graph[friend1].end()) {
                        result.push_back({friend1, friend2});
                    }
                }
            }
        }
    }
}

bool cmp(Pair & p1, Pair & p2) {
    if (p1.id1 != p2.id1) {
        return p1.id1 < p2.id1;
    } else {
        return p1.id2 < p2.id2;
    }
}

void print(vector<Pair> & v) {
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", v.size());
    for (auto & e : v) {
        printf("%04d %04d\n", e.id1, e.id2);
    }
    v.clear();
}

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int id1, id2;
        id1 = toID(s1);
        id2 = toID(s2);
        graph[id1][id2] = true;
        graph[id2][id1] = true;
    }
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        id1 = abs(id1);
        id2 = abs(id2);
        find(id1, id2);
        print(result);
    }
    return 0;
}
