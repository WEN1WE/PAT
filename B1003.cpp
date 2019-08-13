/*
 * 1. 思路足够清晰，才能写出正确的程序
 */


#include <iostream>
using namespace std;

bool judge(string & s) {
    bool flag1 = false, flag2 = false;
    int count1 = 0, count2 = 0, count3 = 0, countP = 0, countT = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'P') {
            flag1 = true;
            countP++;
            continue;
        }
        if (s[i] == 'T') {
            flag2 = true;
            countT++;
            continue;
        }

        if (s[i] == 'A') {
            if (!flag1 && !flag2) {
                count1++;
            } else if (flag1 && !flag2) {
                count2++;
            } else if (flag1 && flag2) {
                count3++;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    return count2 > 0 && (count2 * count1 == count3) && countP == 1 && countT == 1;
}


int main() {
    int n;
    string s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (judge(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
