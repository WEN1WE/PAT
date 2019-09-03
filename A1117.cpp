/*
 * 1. 本题如果做统计，思维会很混乱
 * 2. 最好的思路是逆序，然后数数
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    int N, E = 0;
    scanf("%d", &N);
    vector<int> record(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &record[i]);
    }
    sort(record.begin(), record.end(), cmp);
    
    for (int i = 0; i < N; i++) {
        if (record[i] > i + 1) {
            E++;
        } else {
            break;
        }
    }
    cout << E;
    
    return 0;
}
