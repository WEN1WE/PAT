/*
 * 1. string s; s.length();
 * 2. string s; s[i] 得到第i个位置的元素
 * 3. 对于打印的问题，要清楚知道每一行的关系
 */
#include <iostream>
using namespace std;

int main() {
    int length, left, bottom, right;
    string s;
    cin >> s;
    length = s.length();

    left = right = (length + 2) / 3;
    bottom = length - left - right + 2;

    for (int i = 0; i < left; i++) {
        if (i < left - 1) {
            for (int j = 0; j < bottom; j++) {
                if (j == 0) {
                    cout << s[i + j];
                } else if (j == bottom - 1) {
                    cout << s[length - i - 1];
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        } else {
            for (int j = 0; j < bottom; j++) {
                cout << s[i + j];
            }
        }
    }
    return 0;
}
