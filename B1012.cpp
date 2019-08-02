/*
 * 1. 把变量统一放在数组里操作可以简化命名 count1 count2 count3 = int count[3]
 * 2. 数组统一变为0，int a[5] = {0};
 * 3. int 变 double 输出并且保留一位小数 printf("%.1f ", int * 1.0)
 */

#include <iostream>
using namespace std;

int main() {
    int n, temp, sign = 1;
    int a[5] = {0};
    int count[5] = {0};

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp % 10 == 0) {
            count[0]++;
            a[0] += temp;
        } else if (temp % 5 == 1) {
            count[1]++;
            a[1] += sign * temp;
            sign = -1 * sign;
        } else if (temp % 5 == 2) {
            count[2]++;
        } else if (temp % 5 == 3) {
            count[3]++;
            a[3] += temp;
        } else if (temp % 5 == 4 && temp > a[4]) {
            count[4]++;
            a[4] = temp;
        }
    }

    if (count[0] == 0) {
        cout << 'N' << " ";
    } else {
        cout << a[0] << " ";
    }

    if (count[1] == 0) {
        cout << 'N' << " ";
    } else {
        cout << a[1] << " ";
    }

    if (count[2] == 0) {
        cout << 'N' << " ";
    } else {
        cout << count[2] << " ";
    }

    if (count[3] == 0) {
        cout << 'N' << " ";
    } else {
        printf("%.1f ", a[3] * 1.0 / count[3]);
    }

    if (count[4] == 0) {
        cout << 'N';
    } else {
        cout << a[4];
    }
    return 0;
}

/*
#include <iostream>
using namespace std;

int main() {
    int n, temp;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, sign = 1;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp % 10 == 0) {
            count1++;
            a1 += temp;
        } else if (temp % 5 == 1) {
            count2++;
            a2 += sign * temp;
            sign = -1 * sign;
        } else if (temp % 5 == 2) {
            count3++;
        } else if (temp % 5 == 3) {
            count4++;
            a4 += temp;
        } else if (temp % 5 == 4 && temp > a5) {
            count5++;
            a5 = temp;
        }
    }
    a3 = count3;

    if (count1 == 0) {
        cout << 'N' << " ";
    } else {
        cout << a1 << " ";
    }

    if (count2 == 0) {
        cout << 'N' << " ";
    } else {
        cout << a2 << " ";
    }

    if (count3 == 0) {
        cout << 'N' << " ";
    } else {
        cout << a3 << " ";
    }

    if (count4 == 0) {
        cout << 'N' << " ";
    } else {
        printf("%.1f ", a4 * 1.0 / count4);
    }

    if (count5 == 0) {
        cout << 'N';
    } else {
        cout << a5;
    }

    return 0;
}
 */
