/*
 * 1. string 使用find 时， 没找到用string::npos表示
 * 2. stoi 这个函数在超出int范围或输入为空就会报错，所以最好别用，测试中会有一个很长的数，所以会报错
 */

#include <iostream>
using namespace std;

void addZero(string & s, int significant) {
    if (s.length() < significant) {
        s.append(significant - s.length(), '0');
    } else {
        s = s.substr(0, significant);
    }
}

bool isAllZero(string & s) {
    for (auto e : s) {
        if (e != '0') {
            return false;
        }
    }
    return true;
}

string changeForm(string & s, int significant) {
    int point, k = 0;
    string before, after, temp, together, result;
    if (s.find('.') != string::npos) {
        point = s.find('.');
        before = to_string(stoi(s.substr(0, point)));
        after = s.substr(point + 1);

        if (before == "0") {
            together = to_string(stoi(after));
            k = together.length() - after.length();
            addZero(together, significant);
        } else {
            together = before;
            together.append(after);
            addZero(together, significant);
            k = before.length();
        }
    } else {
        together = s;
        k = together.length();
        addZero(together, significant);
    }

    if (isAllZero(together)) {
        k = 0;
    }
    result = "0." + together + "*10^" + to_string(k);
    return result;
}


int main() {
    int significant;
    string s1, s2, result1, result2;
    cin >> significant >> s1 >> s2;
    result1 = changeForm(s1, significant);
    result2 = changeForm(s2, significant);

    if (result1 == result2) {
        cout << "YES " << result1;
    } else {
        cout << "NO " << result1 << " " << result2;
    }
    return 0;
}
