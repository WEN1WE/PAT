/*
 * 1. map<int, vector<string>> mp, 当改变原来赋值时的vector, map中的值仍然不变
 * 2. 查找元素问题，用map很方便
 */


#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, score;
    map<int, vector<string>> mp;
    vector<string> info(2);
    int highest = 0, lowest = 100;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> info[0] >> info[1] >> score;
        mp[score] = info;

        if (score > highest) {
            highest = score;
        }
        if (score < lowest) {
            lowest = score;
        }
    }
    cout << mp[highest][0] << " " << mp[highest][1] << endl;
    cout << mp[lowest][0] << " " << mp[lowest][1];
    return 0;
}
