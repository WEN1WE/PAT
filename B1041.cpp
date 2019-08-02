/*
 * 1. map 适用于查找型的问题
 * 2. 再map中，vector 可用于value
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<string, vector<string>> mp;
    int n, m;
    string seat;
    vector<string> id(3);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id[0] >> id[1] >> id[2];
        mp[id[1]] = id;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> seat;
        cout << mp[seat][0] << " " << mp[seat][2] << endl;
    }
    return 0;
}
