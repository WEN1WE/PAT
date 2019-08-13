#include <iostream>
using namespace std;

int main() {
    int a, b, sum, d, count = 0;
    int result[32]; // 由于8进制，不用那么多
    cin >> a >> b >> d;
    sum = a + b;

    if (sum == 0) {
        cout << 0;
    }

    while (sum != 0) {
        result[count] = sum % d;
        sum = sum / d;
        count++;
    }
    while (count != 0) {
        cout << result[--count];
    }
}
