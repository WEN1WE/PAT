/*
 * 1. string to int : stoi
 * 2. 本题的贪心策略很巧妙
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2) {
    return s1 + s2 < s2 + s1;
}

int main() {
    int n, first;
    scanf("%d", &n);
    vector<string> segments(n);
    string result;

    for (int i = 0; i < n; i++) {
        cin >> segments[i];
    }
    sort(segments.begin(), segments.end(), cmp);
    for (int i = 0; i < n; i++) {
        result.append(segments[i]);
    }

    first = result.length() - 1;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] != '0') {
            first = i;
            break;
        }
    }
    result = result.substr(first);
    cout << result;
    return 0;
}
