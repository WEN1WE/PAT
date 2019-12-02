/*
 * 1. string 使用find 时， 没找到用string::npos表示
 * 2. stoi 这个函数在超出int范围或输入为空就会报错，所以最好别用，测试中会有一个很长的数，所以会报错
 */

#include <iostream>
using namespace std;

int N;

string getForm (string & s){
    string before, after;
    string result;
    bool flag1 = false, flag2 = false;
    int K = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            flag2 = true;
            continue;
        }

        if (!flag1 && s[i] != '0') {
            flag1 = true;
        }

        if (flag1 && !flag2) {
            before.append(1, s[i]);
        } else if (flag2) {
            after.append(1, s[i]);
        }
    }

    if (before.empty()) {
        bool flag = false;
        for (int i = 0; i < after.size(); i++) {
            if (after[i] != '0') {
                K = -i;
                result = after.substr(i);
                flag = true;
                break;
            }
        }
        if (!flag) {
            result = "0";
            K = 0;
        }
    } else {
        K = before.length();
        result = before + after;
    }

    if (result.length() >= N) {
        result = result.substr(0, N);
    } else {
        result.append(N - result.length(), '0');
    }
    return "0." + result + "*10^" + to_string(K);
}

int main() {
    cin >> N;
    string s1, s2;
    string result1, result2;
    cin >> s1 >> s2;
    
    result1 = getForm(s1);
    result2 = getForm(s2);

    if (result1 == result2) {
        printf("YES %s\n", result1.c_str());
    } else {
        printf("NO %s %s\n", result1.c_str(), result2.c_str());
    }
    return 0;
}

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
