/*
 * 1. to_string(10) = "10"
 * 2. string数组
 * 3. swap 交换两个数，直接把内容交换
 * 4. 本题更好的方法是，直接操作序号，再将序号转变为字符串
 * 5. 转化字符串时，用 / % 找到对应的字符串更加简单
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    int cards[54], temp[54], permutation[54];
    char c[5] = {'S', 'H', 'C', 'D', 'J'};

    cin >> n;
    for (int i = 0; i < 54; i++) {
        cin >> permutation[i];
        cards[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 54; j++) {
            temp[permutation[j] - 1] = cards[j];
        }
        swap(cards, temp);
    }

    for (int i = 0; i < 54; i++) {
        cout << c[cards[i] / 13] << (cards[i] % 13 + 1);
        if (i != 53) {
            cout << " ";
        }
    }
    return 0;
}

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    string cards[54];
    string temp[54];
    int permutation[54];

    cin >> n;
    for (int i = 0; i < 54; i++) {
        cin >> permutation[i];

        if (i < 13) {
            cards[i] = "S" + to_string(i + 1);
        } else if (i < 26) {
            cards[i] = "H" + to_string(i - 12);
        } else if (i < 39) {
            cards[i] = "C" + to_string(i - 25);
        } else if (i < 52) {
            cards[i] = "D" + to_string(i - 38);
        } else if (i == 52) {
            cards[i] = "J1";
        } else {
            cards[i] = "J2";
        }
    }
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 54; j++) {
            temp[permutation[j] - 1] = cards[j];
        }
        swap(cards, temp);
    }

    for (int i = 0; i < 54; i++) {
        cout << cards[i];
        if (i != 53) {
            cout << " ";
        }
    }
    return 0;
}
 */
