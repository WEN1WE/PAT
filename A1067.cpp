/*
 * 1. 此题为贪心问题
 * 2. 运行容易超时
 * 3. 遍历map
      for (auto e : mp) {
        cout << e.first << endl;
        cout << e.second << endl;
      }
 * 4. 使用一个变量表示当前没有排好序的最小的元素，这样复杂度降低了
 * 5. 此题要分清0在开头和0不在开头的情况
 */

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n, value, count = 0;
    scanf("%d", &n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        mp[value] = i;
    }

    for (int i = 1; i < n; i++) {
        while (mp[0] != 0) {
            swap(mp[0], mp[mp[0]]);
            count++;
        }
        if (mp[i] != i) {
            swap(mp[0], mp[i]);
            count++;
        }
    }
    cout << count;
    return 0;
}
