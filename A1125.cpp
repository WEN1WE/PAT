/*
 * 1. 贪心问题，让长度长的绳子少折叠
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> record(n);
    int result;
    double total;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &record[i]);
    }
    sort(record.begin(), record.end());
    
    total = record[0];
    for (int i = 1; i < n; i++) {
        total = (total + record[i]) * 1.0 / 2;
    }
    result = int(floor(total));
    cout << result << endl;
}
