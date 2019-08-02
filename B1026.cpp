/*
 * int i = 7 / 3 得到 i = 2
 * 如何实现四舍五入 用补的方法，实现简单
 * printf 的用法 printf("%02d:%02d:%02d", hh, mm, ss);  00:00:00
 */


#include <iostream>
using namespace std;

int main() {

    int c1, c2;
    int seconds, hh = 0, mm = 0, ss = 0;
    cin >> c1 >> c2;
    seconds = (c2 - c1 + 50) / 100;
    hh = seconds / 3600;
    seconds = seconds % 3600;
    mm = seconds / 60;
    ss = seconds % 60;

    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}
