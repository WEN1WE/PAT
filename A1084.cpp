/*
 * toupper 小写变大写 // 类比 to_string
 * set 的很多用法与map 类似
 */

#include <iostream>
#include <set>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    set<char> broken;

    int j = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[j]) {
            if (broken.find(toupper(s1[i])) == broken.end()) {
                printf("%c", toupper(s1[i]));
                broken.insert(toupper(s1[i]));
            }
        } else {
            j++;
        }
    }
    return 0;
}
