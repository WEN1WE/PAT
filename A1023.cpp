/*
 * 1. 本题调用函数写，很方便
 */


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int carry = 0, temp;
    string s, result, tempS;
    cin >> s;
    reverse(s.begin(), s.end());

    for (auto e : s) {
        temp = (e - '0') * 2 + carry;
        result.append(1, temp % 10 + '0');
        carry = temp / 10;
    }
    if (carry == 1) {
        result.append("1");
    }
    reverse(result.begin(), result.end());
    tempS = result;
    sort(tempS.begin(), tempS.end());
    sort(s.begin(), s.end());
    if (s == tempS) {
        cout << "Yes" << endl;
    }  else {
        cout << "No" << endl;
    }
    cout << result;

    return 0;
}
