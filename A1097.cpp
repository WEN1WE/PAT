/*
 * 1. 本题使用结构体，查找不方便
 * 2. 注意边界，可能没有要去除的节点
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXSIZE = 100010;
int dataRecord[MAXSIZE];
int addressRecord[MAXSIZE];
bool table[10010] = {false};

void print(vector<int> & link) {
    for (int i = 0; i < link.size() - 1; i++) {
        printf("%05d %d %05d\n", link[i], dataRecord[link[i]], link[i + 1]);
    }
    printf("%05d %d -1\n", link[link.size() - 1], dataRecord[link[link.size() - 1]]);
}


int main() {
    int N, current, address, data, next;
    vector<int> record;
    vector<int> removed;
    
    cin >> current >> N;

    for (int i = 0; i < N; i++) {
        cin >> address >> data >> next;
        dataRecord[address] = data;
        addressRecord[address] = next;
    }

    while (current != -1) {
        if (table[abs(dataRecord[current])]) {
            removed.push_back(current);
        } else {
            record.push_back(current);
            table[abs(dataRecord[current])] = true;
        }
        current = addressRecord[current];
    }

    print(record);
    if (!removed.empty()) {
        print(removed);
    }
    
    return 0;
}
