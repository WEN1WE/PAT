/*
 * 1. 理清题意，机械的步骤
 * 2. 此题题意不明，若len(b) < len(a), 还要补全b的高位
 * 3. 由于题目重地位开始计数，所以reverse(a.begin(), a.end()); // 就PAT而言，使用reverse, 要加#include <algorithm>
 * 4. string s; s.append(2, '0'); // 在s的后面加两个零
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int d, len;
    string a, b, result;
    string s = "0123456789JQK";
    cin >> a >> b;
    len = max(a.length(), b.length());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    d = b.length() - a.length();
    if (d > 0) {
        a.append(d, '0');
    } else {
        b.append(-d, '0');
    }

    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            result.append(1, s[(a[i] + b[i] - '0' - '0') % 13]);
        } else {
            result.append(1, (b[i] - a[i] + 10) % 10 + '0');
        }
    }

    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}

/*
#include <iostream>
using namespace std;

int main() {
    bool flag;
    int temp, len;

    string a, b;
    string table = "0123456789JQK";
    cin >> a >> b;
    temp = b.length() - a.length();
    len = max(b.length(), a.length());
    flag = (b.length() % 2 != 0);
    reverse(a.begin(), a.end());
    for (int i = 0; i < len; i++) {
        if (temp >= 0) {
            if (a.length() + i < b.length()) {
                cout << b[i];
            } else if (flag) {
                cout << table[(a[i - temp] + b[i] - '0' - '0') % 13];
            } else {
                cout << (b[i] - a[i - temp] + 10) % 10;
            }
        } else {
            temp = -temp;
            if (flag) {
                cout << table[(a[i + temp] + b[i] - '0' - '0') % 13];
            } else {
                cout << (b[i] - a[i + temp] + 10) % 10;
            }
        }
        flag = !flag;
    }
    return 0;
}
 */
