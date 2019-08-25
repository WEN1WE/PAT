/*
 * 1. 本题为排序题
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, len1, len2, s1 = 0, s2 = 0;
    scanf("%d", &n);
    vector<int> integers(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &integers[i]);
    }
    sort(integers.begin(), integers.end());
    
    len1 = n / 2;
    len2 = n - len1;
    
    for (int i = 0; i < len1; i++) {
        s1 += integers[i];
    }
    for (int i = len1; i < n; i++) {
        s2 += integers[i];
    }
    cout << len2 - len1 << " " << s2 - s1;
    return 0;
}
