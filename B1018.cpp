/*
 * 1. printf("%c", 'a');
 * 2. 由于scanf使用%c时会讲换行符\n读入，因此需要在合适的地方使用getchar()吸收空格
 */

#include <iostream>
#include <map>
using namespace std;

int check(char a, char b) {
    if ((a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C')) {
        return 1;
    } else if (a == b) {
        return 0;
    } else {
        return -1;
    }
}

void record(int win[], char c) {
    if (c == 'B') {
        win[0]++;
    } else if (c == 'C') {
        win[1]++;
    } else if (c == 'J') {
        win[2]++;
    }
}

char getMostWin(int winRecord[]) {
    if (winRecord[1] > winRecord[0] && winRecord[1] >= winRecord[2]) {
        return 'C';
    } else if (winRecord[2] > winRecord[0] && winRecord[2] > winRecord[1]) {
        return  'J';
    } else {
        return 'B';
    }
}

int main() {
    int n, result;
    char temp1, temp2;
    int a[3] = {0};
    int b[3] = {0};
    int winRecordA[3] = {0};
    int winRecordB[3] = {0};
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        result = check(temp1, temp2);
        if (result == 1) {
            a[0]++;
            record(winRecordA, temp1);
        } else if (result == 0) {
            a[1]++;
        } else {
            a[2]++;
            record(winRecordB, temp2);
        }
    }
    b[0] = a[2];
    b[1] = a[1];
    b[2] = a[0];

    printf("%d %d %d\n", a[0], a[1], a[2]);
    printf("%d %d %d\n", b[0], b[1], b[2]);
    printf("%c %c", getMostWin(winRecordA), getMostWin(winRecordB));
}
