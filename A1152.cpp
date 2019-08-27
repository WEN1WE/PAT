/*
 * 1. substr 的使用
 * 2. isPrime 函数
 */

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    } 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int L, K;
    string s;
    scanf("%d %d", &L, &K);
    cin >> s;
    
    if (L < K) {
        printf("404\n");
        return 0;
    }
    
    for (int i = 0; i < L - K + 1; i++) {
        string temp = s.substr(i, K);
        if (isPrime(stoi(temp))) {
            printf("%s\n", temp.c_str());
            return 0;
        }
    }

    printf("404\n");
    return 0;
}
