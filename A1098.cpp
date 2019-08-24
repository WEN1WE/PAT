/*
 * 1. 选择排序时，直接使用sort
 * 2. 注意不要比较刚开始时的序列，序列一定是中间序列
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> initial;
vector<int> partially;
vector<int> tempInitial;

bool insertionSort() {
    bool flag = false;
    for (int i = 2; i <= N; i++) {
        if (flag) {
            break;
        }
        if (i != 2 && partially == tempInitial) {
            flag = true;
        }
        sort(tempInitial.begin() + 1, tempInitial.begin() + i + 1);
    }
    return flag;
}

void sink(int k, int n) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && tempInitial[j] < tempInitial[j + 1]) 
            j++;
        if (tempInitial[k] >= tempInitial[j]) 
            break;
        swap(tempInitial[k], tempInitial[j]);
        k = j;
    }
}

bool heapSort() {
    bool flag = false;
    int n = N;
    for (int k = N / 2; k >= 1; k--) {
        sink(k, n);
    }
    while (n > 1) {
        if (flag) {
            break;
        }
        
        if (n != N && partially == tempInitial) {
            flag = true;
        }
        
        swap(tempInitial[1], tempInitial[n]);
        sink(1, --n);
    }
    return flag;
}

void print(vector<int> & sequence) {
    for (int i = 1; i <= N; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << sequence[i];
    }
}

int main() {
    scanf("%d", &N);
    initial.resize(N + 1);
    partially.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &initial[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &partially[i]);
    }
    
    tempInitial = initial;
    if (insertionSort()) {
        printf("Insertion Sort\n");
        print(tempInitial);
        return 0;
    }

    tempInitial = initial;
    if (heapSort()) {
        printf("Heap Sort\n");
        print(tempInitial);
    }
    return 0;
}
