/*
 * 1. 题目边界，开始就为回文数，直接输出
 */

#include <iostream>
#include <algorithm>
using namespace std;

string add(string & s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    string result;
    int carry = 0;
    int sum;
    
    for (int i = 0; i < s1.length(); i++) {
        sum = s1[i] - '0' + s[i] - '0' + carry;
        result.append(to_string(sum % 10));
        carry = sum / 10;
    }
    if (carry != 0) {
        result.append(to_string(carry));
    }
    reverse(result.begin(), result.end());
    printf("%s + %s = %s\n", s.c_str(), s1.c_str(), result.c_str());
    
    return result;
}

bool isPalindrome (string & s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
}

int main() {
    int count = 0;
    string s;
    cin >> s;
    
    if (isPalindrome(s)) {
        printf("%s is a palindromic number.\n", s.c_str());
        return 0;
    }
    
    do {
        s = add(s);
        count++;
    } while (!isPalindrome(s) && count < 10);
    
    if (isPalindrome(s)) {
        printf("%s is a palindromic number.\n", s.c_str());
    } else {
        printf("Not found in 10 iterations.\n");
    }
    
    return 0;
}
