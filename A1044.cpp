/*
 * 1. #include <cmath> // pow
 * 2. binarySearch 找到第一个小于等于的值
 * 3. 本题要考虑越界的情况
 * 4. radix 不仅为36
 */

#include <iostream>
#include <algorithm>
using namespace std;

long long toDigit(char c) {
    if (c >= 'a') {
        return c - 'a' + 10;
    } else {
        return c - '0';
    }
}

long long toTen(string s, long long radix) {
    long long result = 0;
    for (char c : s) {
        result = result * radix + toDigit(c);
        if (result < 0) {  // 越界
            return -1;
        }
    }
    return result;
}

long long getLeft(string s) {
    long long left = -1, temp;
    for (char c : s) {
        temp = toDigit(c);
        if (left <= toDigit(c)) {
            left = temp + 1;
        }
    }
    return left;
}

long long binarySearch(string s, long long value) {
    long long left = getLeft(s), right = value + 1, mid, temp;

    while (left < right) {
        mid = (left + right) / 2;
        temp = toTen(s, mid);
         if (temp == -1 || temp >= value){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    string N1, N2, s1, s2;
    long long value, radix, temp;
    int tag;
    cin >> N1 >> N2 >> tag >> radix;
    s1 = tag == 1 ? N1 : N2;
    s2 = tag == 1 ? N2 : N1;
    value = toTen(s1, radix);
    temp = binarySearch(s2, value);

    if (toTen(s2, temp) == value) {
        cout << temp;
    } else {
        cout << "Impossible";
    }
    return 0;
}
