/*
 * 1. map的使用
 */

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, value, result = 1;
    scanf("%d", &n);
    map<int, bool> mp;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (value > 0) {
            mp[value] = true;
        }
    }
    while (true) {
        if (mp.find(result) == mp.end()) {
            break;
        }
        result++;
    }
    cout << result;
    return 0;
}
