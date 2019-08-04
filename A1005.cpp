/*
 * 1。使用for each 遍历字符串很方便
 */


#include <iostream>
using namespace std;

int main() {
    bool flag = false;
    int sum = 0;
    string s, sumS;
    string table[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> s;

    for (auto e : s) {
        sum += (e - '0');
    }
    sumS = to_string(sum);

    for (auto e : sumS) {
        if (flag) {
            cout << " ";
        }
        flag = true;
        cout << table[e - '0'];
    }
    return 0;
}
