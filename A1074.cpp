/*
 * 1. 本题的要点就是不要看作链表
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXSIZE = 100010;

int main() {
    int current, N, K, address, data, next;
    int dataRecord[MAXSIZE];
    int addressRecord[MAXSIZE];
    vector<int> record;
    
    cin >> current >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> address >> data >> next;
        dataRecord[address] = data;
        addressRecord[address] = next;
    }
    
    while (current != -1) {
        record.push_back(current);
        current = addressRecord[current];
    }
    
    for (int i = 1; i * K <= record.size(); i++) {
        reverse(record.begin() + (i - 1) * K, record.begin() + i * K);
    }
    
    for (int i = 0; i < record.size() - 1; i++) {
        printf("%05d %d %05d\n", record[i], dataRecord[record[i]], record[i + 1]);
    }
    printf("%05d %d -1", record[record.size() - 1], dataRecord[record[record.size() - 1]]);
    return 0;
}
