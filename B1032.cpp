/*
 * 1. 搜集信息的时候，使用map很方便
 * 2. 判断元素是否为key时候 mp.find(id) == mp.end()
 * 3. 迭代 map : for (auto it : mp)
 * 4. for (auto & it : mp) 与 for (auto it : mp) 的区别，使用引用可以改变map中的值
 */


#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, id, score, bestSchool = 0, highest = 0;
    map<int, int> mp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> id >> score;
        if (mp.find(id) == mp.end()) {
            mp[id] = score;
        } else {
            mp[id] += score;
        }
    }

    for (auto it : mp) {
        if (highest < it.second) {
            highest = it.second;
            bestSchool = it.first;
        }
    }
    cout << bestSchool << " " << highest <<endl;
    return 0;
}
