/*
 * 1. tolower() toupper()的使用
 * 2. 在原来字符串后面加一个'!'，表示结束，避免特殊情况
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cnt = 0;
    string s, result, temp;
    unordered_map<string, int> mp;
    getline(cin, s);
    s.append(1, '!');
    
    for (auto c : s) {
        if (isalnum(c)) {
            c = tolower(c);
            temp.append(1, c);
        } else if (!temp.empty()){
            if (mp.find(temp) == mp.end()) {
                mp[temp] = 1;
            } else {
                mp[temp]++;
            }
            if (mp[temp] > cnt || ((mp[temp] == cnt) && temp < result)) {
                cnt = mp[temp];
                result = temp;
            }
            temp.clear();
        }
    }
    
    cout << result << " " << cnt << endl;

    return 0;
}



#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool isAlphanumerical(char c) {
    return isalpha(c) || isdigit(c);
}

int main() {
    int maxTimes = 0;
    string s, temp;
    map<string, int> mp;
    vector<string> result;
    getline(cin, s);
    s.append(1, '!');

    for (auto c : s) {
        if (isAlphanumerical(c)) {
            c = tolower(c);
            temp.append(1, c);
        } else if (!temp.empty()){
            if (mp.find(temp) == mp.end()) {
                mp[temp] = 1;
            } else {
                mp[temp]++;
            }
            temp.clear();
        }
    }

    for (auto e : mp) {
        if (e.second > maxTimes) {
            maxTimes = e.second;
        }
    }

    for (auto e : mp) {
        if (e.second == maxTimes) {
            result.push_back(e.first);
        }
    }

    sort(result.begin(), result.end());
    cout << result[0] << " " << maxTimes;
    return 0;
}
