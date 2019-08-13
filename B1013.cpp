#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
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
    int m, n, temp = 2, count = 0;
    cin >> m >> n;

    while (count != n) {
        if(isPrime(temp)) {
            count++;
            if (count >= m) {
                if ((count - m + 1) % 10 != 1) {
                    cout << " ";
                }
                cout << temp;
                if ((count - m + 1) % 10 == 0) {
                    cout << endl;
                }
            }
        }
        temp++;
    }
    return 0;
}

