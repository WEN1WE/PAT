/*
 * 1. getline(cin , s) 会读取行末尾的换行符，因此要及时使用 getchar();
 * 2. 注意边界，13 不输入个位的0
 */

#include <iostream>
#include <map>
using namespace std;

const string lower[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string higher[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main() {
    int N, unit, decade;
    string number, unitS, decadeS;
    map<string, int> mp;
    for (int i = 0; i < 13; i++) {
        mp[lower[i]] = i;
        mp[higher[i]] = 13 * i;
    }
    cin >> N;
    getchar();
    for(int i = 0; i < N; i++) {
        getline(cin, number);
        if (number[0] >= '0' && number[0] <= '9') {
            int n = stoi(number);
            unit = n % 13;
            decade = n / 13;
            if (decade > 0) {
                if (unit != 0) {
                    cout << higher[decade] << " " << lower[unit] << endl;
                } else {
                    cout << higher[decade] << endl;
                }
            } else {
                cout << lower[unit] << endl;

            }
        } else {
            if (number.size() > 4) {
                unitS = number.substr(4);
                decadeS = number.substr(0, 3);
                cout << mp[decadeS] + mp[unitS] << endl;
            } else {
                cout << mp[number] << endl;
            }
        }
    }
    return 0;
}
