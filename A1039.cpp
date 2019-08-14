/*
 * 1. map 使用for each, 并不能对value 进行sort
 * 2. 本题使用map超时，cout, cin 也超时
 * 3. 本题使用vector数组 students[M]
 */

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
