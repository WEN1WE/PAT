/*
 * 1. 本题如果做统计，思维会很混乱
 * 2. 最好的思路是逆序，然后数数
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int i, int j) {
    return i > j;
}

int main() {
    int n, E = 0; 
    scanf("%d", &n);
    vector<int> record(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &record[i]);
    }
    sort(record.begin(), record.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        if (record[i] > i + 1) {
            E = i + 1;
        } else {
            break;
        }
    }
    cout << E << endl;

    return 0;
}
