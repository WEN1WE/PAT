#include <iostream>
#include <map>
using namespace std;

int main() {
    int m, n, color, total;
    map<int, int> mp;
    cin >> m >> n;
    total = n * m;
    for (int i = 0; i < total; i++) {
        cin >> color;
        if (mp.find(color) == mp.end()) {
            mp[color] = 1;
        } else {
            mp[color]++;
        }
    }

    for (auto e : mp) {
        if (e.second * 2 > total) {
            cout << e.first;
        }
    }
    return 0;
}
