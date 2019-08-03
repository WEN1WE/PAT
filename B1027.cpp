/*
 * 1. 每一行结尾的空格不用考虑，否则会报错
 * 2. 使用递归来写，会使代码更加清晰
 */


#include <iostream>
#include <cmath>
using namespace std;

string getLine(int level, int space, string c) {
    string s;
    for (int i = 0; i < level; i++) {
        if (i < space) {
            s.append(" ");
        } else if (i < level - space){
            s.append(c);
        }
    }
    return s;
}

void print(int level, int space, string c) {
    string s;
    s = getLine(level, space, c);
    if (space == level / 2) {
        cout << s << endl;
    } else {
        cout << s << endl;
        print(level, space + 1, c);
        cout << s << endl;
    }
}

int sum(int level) {
    return pow(level + 1, 2) / 2 - 1;
}

int main() {
    int n, level, rest;
    string c;
    cin >> n >> c;

    for (level = 1;  sum(level) <= n; level += 2);
    level -= 2;
    rest = n - sum(level);

    print(level, 0, c);
    cout << rest;
    return 0;
}
