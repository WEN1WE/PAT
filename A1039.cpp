/*
 * 1. map 使用for each, 并不能对value 进行sort
 * 2. 本题使用map超时，cout, cin 也超时
 * 3. 本题使用vector数组 students[M], 将string 转化为 id
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 26 * 26 * 26 * 10 + 1;

int getID(char name[]) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}


int main() {
    int N, K, id;
    char name[5];
    vector<int> students[MAX];
    scanf("%d %d", &N, &K);

    for (int i = 0; i < K; i++) {
        int course, n;
        scanf("%d %d", &course, &n);
        for (int j = 0; j < n; j++) {
            scanf("%s", name);
            id = getID(name);
            students[id].push_back(course);
        }
    }

    for (int i = 0; i < N; i++) {
        scanf("%s", name);
        id = getID(name);
        sort(students[id].begin(), students[id].end());
        printf("%s %d", name, students[id].size());
        for (int j = 0; j < students[id].size(); j++) {
            printf(" %d", students[id][j]);
        }
        printf("\n"); 
    }
    return 0;
}



#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    string name;
    map<string, vector<int>> mp;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int course, n;
        cin >> course >> n;

        for (int j = 0; j < n; j++) {
            cin >> name;
            mp[name].push_back(course);
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> name;
        cout << name << " ";
        cout << mp[name].size();

        sort(mp[name].begin(), mp[name].end());
        for (auto e : mp[name]) {
            cout << " ";
            cout << e;
        }
        cout << endl;
    }
    return 0;
}
