/*
 * 1. 注意除以0的情况
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s;
        s1 = s.substr(0, s.size() / 2);
        s2 = s.substr(s.size() / 2);
        if (stoi(s1) != 0 && stoi(s2) != 0 && stoi(s) % (stoi(s1) * stoi(s2)) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
