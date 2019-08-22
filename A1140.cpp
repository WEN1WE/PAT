/*
 * 1. 本题也可以使用两个指针i, j来做
 */
#include <iostream>
using namespace std;

string lookAndSay(string & s) {
    char current = s[0];
    int count = 0;
    string result;
    for (char c : s) {
        if (current == c) {
            count++;
        } else {
            result.append(1, current);
            result.append(to_string(count));
            current = c;
            count = 1;
        }
    }
    return result ;
}

int main() {
    int n;
    string s;
    cin >> s >> n;
    
    for (int i = 0; i < n - 1; i++) {
        s.append("*");
        s = lookAndSay(s);
    }
    cout << s;
    return 0;
}
