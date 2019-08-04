/*
 * 1. int to string: to_string
 * 2. string to int: stoi()
 * 3. 把大问题化成小问题解决
 */

#include <iostream>
using namespace std;

string table1[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string table2[] = {"", " Shi", " Bai", " Qian"};

void print(string s) {
    if (s[0] == '0') {
        cout << "ling" << " ";
        s = to_string(stoi(s));
    }

    bool flag = true;
    bool flag2 = false;  // 保证末尾没有空格
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            flag = false;
            continue;
        }
        if (s[i] != '0' && !flag) {
            flag = true;
            cout << " ling";
        }

        if (flag) {
            if (flag2) {
                cout << " ";
            }
            flag2 = true;
            cout << table1[s[i] - '0'] << table2[len - i - 1];
        }
    }
}

int main() {
    int len;
    string s, s1, s2, s3;
    cin >> s;

    if (stoi(s) == 0) {
        cout << "ling";
        return 0;
    }

    if (s[0] == '-') {
        cout << "Fu ";
        s = s.substr(1);
    }

    len = s.length();



    if (len == 9) {
        s1 = s.substr(0, 1);
        s2 = s.substr(1, 4);
        s3 = s.substr(5);
    } else if (len > 4) {
        s2 = s.substr(0, len - 4);
        s3 = s.substr(len - 4);
    } else {
        s3 = s.substr(0);
    }

    if (!s1.empty()) {
        cout << table1[stoi(s1)] << " " << "Yi";
        if (stoi(s2) != 0) {
            cout << " ";
            print(s2);
            cout << " Wan";
        }
        if (stoi(s3) != 0) {
            cout << " ";
            print(s3);
        }
    } else if (!s2.empty()) {
        print(s2);
        cout << " Wan";
        if (stoi(s3) != 0) {
            cout << " ";
            print(s3);
        }
    } else {
        print(s3);
    }
    return 0;
}
