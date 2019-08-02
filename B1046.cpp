#include <iostream>
using namespace std;

int main() {
    int n;
    int count1 = 0, count2 = 0;
    int a1, a2, b1, b2;
    int sum;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a1 >> a2 >> b1 >> b2;
        sum = a1 + b1;
        if (a2 != sum && b2 == sum) {
            count1++;
        }
        if (a2 == sum && b2 != sum) {
            count2++;
        }
    }
    printf("%d %d\n", count1, count2);
    return 0;
}
