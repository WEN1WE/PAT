/*
 * 1. 本题主要考察的是map的使用
 * 2. 数字符串的技巧，就是在后面添加一个末尾
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int k, count = 0;
    string s, original, stucked;
    char last = '*';
    scanf("%d", &k);
    map<char, bool> possible;
    map<char, bool> impossible;
    map<char, bool> result;
    map<char, bool> detected;
    
    cin >> s;
    s.append(1, '*');
    
    count = 1;
    last = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != last) {
            if (count % k == 0) {
                possible[last] = true;
            } else {
                impossible[last] = true;
            }
            count = 1;
            last = s[i];
        } else {
            count++;
        }
    }
    
    for (auto e : possible) {
        if (impossible.find(e.first) == impossible.end()) {
            result[e.first] = true;
        }
    }
    
    for (int i = 0; i < s.size() - 1; i++) {
        original.append(1, s[i]);
        if (result.find(s[i]) != result.end()) {
            i += k - 1;
            if (detected.find(s[i]) == detected.end()) {
                stucked.append(1, s[i]);
                detected[s[i]] = true;
            }
        } 
    }
    
    cout << stucked << endl;
    cout << original << endl;
    return 0;
}
