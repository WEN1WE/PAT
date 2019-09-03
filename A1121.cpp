/*
 * 1. map的使用
 * 2. 此题结尾不能多打印一个换行符
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int N, M;
    scanf("%d", &N);
    map<int, int> mp;
    map<int, int> guests;
    vector<int> record;
    vector<int> result;
    
    for (int i = 0; i < N; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        mp[c1] = c2;
        mp[c2] = c1;
    }
    
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int c;
        scanf("%d", &c);
        record.push_back(c);
        guests[c] = true;
    }
    
    for (int i = 0; i < M; i++) {
        if (guests.find(mp[record[i]]) == guests.end()) {
            result.push_back(record[i]);
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
