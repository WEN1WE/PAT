/*
 * 1. map的使用
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> mp;
    map<int, bool> record;
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        mp[id1] = id2;
        mp[id2] = id1;
    } 
    
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        record[id] = true;
    }
    
    for (auto e : record) {
        if (mp.find(e.first) == mp.end()) {
            result.push_back(e.first);
        } else {
            int other = mp[e.first];
            if (record.find(other) == record.end()) {
                result.push_back(e.first);
            }
        }
    }
    sort(result.begin(), result.end());
    printf("%d\n", result.size());
    for (int i = 0; i < result.size(); i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%05d", result[i]);
    }
    return 0;
}
