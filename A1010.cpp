/*
 * 1. #include <cmath> // pow
 */

#include <iostream>
#include <algorithm>
using namespace std;

long long toTen(string s, int radix) {
    long long result = 0;
    for (char i : s) {
        if (i >= 'a') {
            result = result * radix + i - 'a' + 10;
        } else {
            result = result * radix + i - '0';
        }
    }
    return result;
}

int binarySearch(string s, long long value) {
    int left = 0, right = 35, mid;

    for (char c : s) {
        if (c >= 'a') {
            left = max(left, c - 'a' + 10);
        } else {
            left = max(left, c - '0');
        }
    }

    long long temp;
    while (left < right) {
        mid = (left + right) / 2;
        temp = toTen(s, mid);
         if (temp >= value){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    string N1, N2, s;
    long long value;
    int tag, radix;
    int temp;
    cin >> N1 >> N2 >> tag >> radix;

    if (tag == 1) {
        value = toTen(N1, radix);
        s = N2;
    } else {
        value = toTen(N2, radix);
        s = N1;
    }

    temp = binarySearch(s, value);
    if (toTen(s, temp) == value) {
        cout << temp;
    } else {
        cout << "Impossible";
    }
    return 0;
}
