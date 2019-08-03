/*
 * 1. 采用直接输出的方式，不用存起来
 */

#include <iostream>
using namespace std;

int main() {
    int red, green, blue;
    string s = "0123456789ABC";
    cin >> red >> green >> blue;
    cout << "#";

    cout << s[red / 13];
    cout << s[red % 13];
    cout << s[green / 13];
    cout << s[green % 13];
    cout << s[blue / 13];
    cout << s[blue % 13];

    return 0;
}
