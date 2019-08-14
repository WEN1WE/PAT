/*
 * 1. 注意边界，开始输入就是回文数
 * 2. 使用字符串做大整数运算，很方便
 */

#include <iostream>
#include <algorithm>
using namespace std;

string add(string & s) {
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(), s2.end());

    string result;
    int carry = 0, temp;

    for (int i = 0; i < s.length(); i++) {
        temp = (s1[i] - '0') + (s2[i] - '0') + carry;
        result.append(1, temp % 10 + '0');
        carry = temp / 10;
    }
    if (carry == 1) {
        result.append("1");
    }
    reverse(result.begin(), result.end());
    return result;
}

bool isPalindromic(string s) {
    string temp = s;
    reverse(s.begin(), s.end());
    return s == temp;
}

int main() {
    string s, result;
    int step, count = 0;
    cin >> s >> step;
    result = s;

    for (int i = 0; i < step; i++) {
        if (isPalindromic(result)) {
            break;
        }
        result = add(result);
        count++;

    }
    cout << result << endl;
    cout << count;
}
