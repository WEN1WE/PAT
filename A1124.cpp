/*
 * 1. 理清题意，一步一步数
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    bool flag = false;
    int m, n, s, count = 0;
    scanf("%d %d %d", &m, &n, &s);
    map<string, bool> mp;
    vector<string> result;
    string st;
    
    for (int i = 1; i <= m; i++) { 
        cin >> st;
        if (flag) {
            count++;
        }
        if (i == s || count == n) {
            if (mp.find(st) != mp.end()) {
                count--;
                continue;
            }
            flag = true;
            cout << st << endl;
            mp[st] = true;
            count = 0;
        }
    }
    if (!flag) {
        printf("Keep going...\n");
    }
    return 0;
}
