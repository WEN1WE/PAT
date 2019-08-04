/*
 * 1. 一些临时变量，下次循环前要初始化
 * 2. map = {{, }, {, }} // map初始化
 */

#include <iostream>
#include <map>
using namespace std;

int main() {
    bool flag = false;
    int n, count = 0;
    string temp, name, password;
    map<char, char> mp = {{'1','@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
    cin >> n;
    string result[n];

    for (int i = 0; i < n; i++) {
        cin >> name >> password;
        for (auto e : password) {
            if (mp.find(e) != mp.end()) {
                flag = true;
                temp.append(1, mp[e]);
            } else {
                temp.append(1, e);
            }
        }
        if (flag) {
            result[count++] = name.append(" ").append(temp);
        }
        flag = false;
        temp = "";
    }

    if (count) {
        cout << count << endl;
        for (int i = 0; i < count; i++) {
            cout << result[i] << endl;
        }
    } else {
        if (n == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    }
    return 0;
}
