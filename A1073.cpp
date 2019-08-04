/*
 * 1. string to in : stoi("111") = 111
 * 2. string s; s.find( );  // 找到某个元素的位置
 * 3. string s; s.substr(1, 3);  // 从起点为1， 输出3个元素子字符串，若后面没有数字，则表示一直到末尾
 * 4. 此题主要是先记录，再分情况讨论
 * 5. 与B1024相同
 */

#include <iostream>
using namespace std;

int main() {
    bool flag = true;
    string s;
    string base;
    string temp;
    int exp;
    char sign = ' ';

    cin >> s;

    if (s[0] == '-') {
        cout << '-';
    }
    s.find('E');

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '.') {
            continue;
        } else if (s[i] == 'E') {
            flag = false;
            sign = s[++i];
            continue;
        }
        if (flag) {
            base.append(1, s[i]);
        } else {
            temp.append(1, s[i]);
        }
    }
    exp = stoi(temp);

    if (sign == '+') {
        if (base.length() - 1 <= exp) {
            cout << base;
            for (int i = 0; i < exp - base.length() + 1; i++) {
                cout << '0';
            }
        } else {
            for (int i = 0; i < base.length(); i++) {
                cout << base[i];
                if (i == exp) {
                    cout << '.';
                }
            }
        }
    } else {
        cout << "0.";
        for (int i = 0; i < exp - 1; i++) {
            cout << '0';
        }
        cout << base;
    }
    return 0;
}
