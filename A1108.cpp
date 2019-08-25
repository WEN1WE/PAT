/*
 * 1. isdigit() only works with 0-9.
 * 2. k = 1, 要单独说
 * 3. stod的使用
 * 4. 本题也可以用  sscanf() – 从一个字符串中读进与指定格式相符的数据
                  sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中
 */

#include <iostream>
using namespace std;

bool check(string s) {
    int pCount = 0;
    int accurate = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            if (!(s[i] == '-' || isdigit(s[i]))) {
                return false;
            }
            continue;
        }
        if (!(isdigit(s[i]) || s[i] == '.')) {
            return false;
        }
        if (s[i] == '.') {
            pCount++;
            continue;
        }
        if (pCount > 1) {
            return false;
        }
        if (pCount == 1) {
            accurate++;
        }
    }
    return accurate <= 2 && stod(s) <= 1000 && stod(s) >= -1000;
}

int main() {
    int n, count = 0;
    double sum = 0;
    string s;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (check(s)) {
            sum += stod(s);
            count++;
        } else {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        }
    }
    if (count == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (count == 1) {
        printf("The average of 1 number is %.2f\n", sum);
    } else {
        printf("The average of %d numbers is %.2f\n", count, sum / count);

    }
    return 0;
}
