/*
 * 1. 对于链表的问题，不要看成链表简单
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100010;

int main() {
    vector<int> negative;
    vector<int> smaller;
    vector<int> greater;
    vector<int> link;
    
    int first, n, k, current;
    int address[MAX];
    int data[MAX];
    cin >> first >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> current;
        cin >> data[current] >> address[current];
    }
    
    current = first;
    while (current != -1) {
        link.push_back(current);
        current = address[current];
    }
    
    for (auto e : link) {
        if (data[e] < 0) {
            negative.push_back(e);
        } else if (data[e] <= k) {
            smaller.push_back(e);
        } else {
            greater.push_back(e);
        }
    }
    
    link.clear();
    for (auto e : negative) {
        link.push_back(e);
    }
    for (auto e : smaller) {
        link.push_back(e);
    }
    for (auto e : greater) {
        link.push_back(e);
    }
    
    for (int i = 0; i < link.size() - 1; i++) {
        printf("%05d %d %05d\n", link[i], data[link[i]], link[i + 1]);
    }
    printf("%05d %d -1\n", link[link.size() - 1], data[link[link.size() - 1]]);
    return 0;
}
