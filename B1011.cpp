/*
 * cin cout 的用法
 * to_string 的用法
 */

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        double a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        if (a + b > c) {
            cout << "Case #" + to_string(i + 1) + ": " + "true" << endl;
        } else {
            cout << "Case #" + to_string(i + 1) + ": " + "false" << endl;
        }
    }
    return 0;
}
