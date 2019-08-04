/*
 * 1. getchar() 可以接收换行符，转到下一行
 * 2. string s; s.empty(); // 判空
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    bool flag = false;
    int n;
    cin >> n;
    int minLength = 300;
    string lines[n], suffix;
    getchar();   // 接收换行符

    for (int i = 0; i < n; i++) {
        getline(cin, lines[i]);
        reverse(lines[i].begin(), lines[i].end());
        minLength = min(minLength, int(lines[i].length()));
    }

    for (int i = 0; i < minLength; i++) {
        char temp = lines[0][i];
        for (int j = 0; j < n; j++) {
            if (temp != lines[j][i]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        } else {
            suffix.append(1, temp);
        }
    }
    if (suffix.empty()) {
        cout << "nai";
    } else {
        reverse(suffix.begin(), suffix.end());
        cout << suffix;
    }
    return 0;
}
