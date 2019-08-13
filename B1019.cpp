/*
 * 1. string vector 的 == 都可以直接比较每个元素相同
 * 2. string b = a; //  b有自己的一份拷贝
 * 3. 考虑输入的数字小于1000的情况
 * 4. 添加0的时候，可以用s.insert
 * 5. 使用do while 就可以保证进行一次循环， 简化代码
 */

#include <iostream>
#include <algorithm>
using namespace std;

const string table[4] = {"", "0", "00", "000"};
bool cmp(char c1, char c2) {
    return c1 > c2;
}

void addZero(string & s) {
    string temp;
    temp = table[4 - s.length()];
    s = temp.append(s);
}

int main() {
    string s, big, small, result, temp;
    cin >> s;
    addZero(s);
    big = s;
    small = s;
    sort(small.begin(), small.end());
    sort(big.begin(), big.end(), cmp);

    while (true) {
        result = to_string(stoi(big) - stoi(small));
        addZero(result);
        printf("%s - %s = %s\n", big.c_str(), small.c_str(), result.c_str());

        if (result == "0000" || result == "6174") {
            break;
        }

        big = result;
        small = result;
        sort(small.begin(), small.end());
        sort(big.begin(), big.end(), cmp);
    }
    return 0;
}
