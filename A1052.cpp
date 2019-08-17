/*
 * 1. 本题的技巧也是不要看作链表
 * 2. 有一个边界就是没有收集到数据
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXSIZE = 100010;

struct Node {
    int address;
    int key;
} node;

bool cmp(Node n1, Node n2) {
    return n1.key < n2.key;
}

int main() {
    int N, current, address, data, next;
    int dataRecord[MAXSIZE];
    int addressRecord[MAXSIZE];
    vector<Node> record;
    
    cin >> N >> current;

    for (int i = 0; i < N; i++) {
        cin >> address >> data >> next;
        dataRecord[address] = data;
        addressRecord[address] = next;
    }

    while (current != -1) {
        node.address = current;
        node.key = dataRecord[current];
        record.push_back(node);
        current = addressRecord[current];
    }
    
    sort(record.begin(), record.end(), cmp);
    
    if (record.empty()) {
        printf("0 -1");
    } else {
        printf("%d %05d\n", record.size(), record[0].address);
        for (int i = 0; i < record.size() - 1; i++) {
            printf("%05d %d %05d\n", record[i].address, record[i].key, record[i + 1].address);
        }
        printf("%05d %d -1", record[record.size() - 1].address, record[record.size() - 1].key);
    }
    return 0;
}
