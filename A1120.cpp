#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(string & s) {
    int sum = 0;
    for (auto e : s) {
        sum += e - '0';
    }
    return sum;
}

int main() {
    int n;
    string s;
    scanf("%d", &n);
    map<int, bool> mp;
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[getSum(s)] = true;
    }
    
    cout << mp.size() << endl;
    for (auto e : mp) {
        result.push_back(e.first);
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    return 0;
}
