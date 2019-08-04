/*
 * 1. printf 输出字符串不方便 %s 为字符数组 char a[]
 * 2. string s; printf("%s"), s.c_str())
 * 3. 本题主要难点在于怎么确定范围
 * 4. isdigit() 可以用来判断数字(字符）(isdigit('1')  0-9
 * 5. isalpha() 可以用来判断字母 isalpha('a')  isalpha('A') a-z A-Z
 * 6. 与B1014为同一题
 */

#include <iostream>
using namespace std;

int main() {
    bool sign = true;
    int hour = 0, minute = 0;
    string table[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string s1, s2, s3, s4;
    string day;
    cin >> s1 >> s2 >> s3 >> s4;
    int length1 = min(s1.length(), s2.length());
    int length2 = min(s3.length(), s4.length());

    for (int i = 0; i < length1; i++) {
        if (s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i] && sign) {
            day = table[s1[i] - 'A'];
            sign = false;
        } else if (((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N')) && s1[i] == s2[i] && !sign) {
            if (s1[i] >= 'A') {
                hour = s1[i] - 'A' + 10;
            } else {
                hour = s1[i] - '0';
            }
            break;
        }
    }

    for (int i = 0; i < length2; i++) {
        if (isalpha(s3[i]) && s3[i] == s4[i]) {
            minute = i;
            break;
        }
    }

    printf("%s %02d:%02d", day.c_str(), hour, minute);

    return 0;

}
