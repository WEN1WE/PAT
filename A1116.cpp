/*
 * 1. map的使用
 */

#include <iostream>
#include <map>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, id, k;
    scanf("%d", &n);
    map<int, int> mp;
    map<int, bool> checked;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &id);
        mp[id] = i;
    }
    
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &id);
        if (checked.find(id) != checked.end()) {
            printf("%04d: Checked\n", id);
        } else if (mp.find(id) == mp.end()) {
            printf("%04d: Are you kidding?\n", id);
        } else if (mp[id] == 1) {
            checked[id] = true;
            printf("%04d: Mystery Award\n", id);
        } else if (isPrime(mp[id])) {
            checked[id] = true;
            printf("%04d: Minion\n", id);
        } else {
            checked[id] = true;
            printf("%04d: Chocolate\n", id);
        }
    }
    
    return 0;
}
