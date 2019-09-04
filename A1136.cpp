/*
 * 1. 题目边界，开始就为回文数，直接输出
 */

#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string & original) {
    string reversed = original;
    reverse(reversed.begin(), reversed.end());
    return reversed == original;
}

string add(string & original, string & reversed) {
    string result;
    int carry = 0;
    for (int i = 0; i < original.size(); i++) {
        int sum = original[i] - '0' + reversed[i] - '0' + carry;
        int digit = sum % 10;
        carry = sum / 10;
        result.append(to_string(digit));
    }
    if (carry != 0) {
        result.append(to_string(carry));
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int cnt = 0;
    string original;
    cin >> original;
    
    while (!isPalindrome(original) && cnt < 10) {
        string reversed = original;
        reverse(reversed.begin(), reversed.end());
        printf("%s + %s = ", original.c_str(), reversed.c_str());
        original = add(original, reversed);
        printf("%s\n", original.c_str());
        cnt++;
    }
    if (isPalindrome(original)) {
        printf("%s is a palindromic number.\n", original.c_str());
    } else {
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}
