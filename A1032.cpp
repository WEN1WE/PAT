/*
 * 1. 本题的解法比较常规，先存储，再比较
 * 2. 也可以使用开关的思想来解
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXSIZE = 100010;

int main() {
    char data;
    int current1, current2, N, address, next, len, common = -1;
    int addressRecord[MAXSIZE];
    vector<int> record1;
    vector<int> record2;
    
    cin >> current1 >> current2 >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> address >> data >> next;
        addressRecord[address] = next;
    }

    while (current1 != -1) {
        record1.push_back(current1);
        current1 = addressRecord[current1];
    }
    reverse(record1.begin(), record1.end());
    while (current2 != -1) {
        record2.push_back(current2);
        current2 = addressRecord[current2];
    }
    reverse(record2.begin(), record2.end());

    len = min(record1.size(), record2.size());
    for (int i = 0; i < len; i++) {
        if (record1[i] == record2[i]) {
            common = i;
        } else {
            break;
        }
    }
    if (common == -1) {
        printf("-1");
    } else {
        printf("%05d", record1[common]);
    }
    return 0;
}
