/*
 * 1. string to int: string s = "100"; int i = stoi(s); // i = 100
 * 2. scanf("%s"，name) 配合的类型为 char name[5]，并且不用加&
 * 3. 考虑边界为0的情况
 * 4. 将日期的比较转化为数字的比较更加简单
 * 5. 对于多种信息集合的问题，结构体会使代码简单
 */


#include <iostream>
using namespace std;

bool isReasonable(int time) {
    return !(time > 20140906 || time < 18140906);
}

struct info {
    string name;
    int time;
}oldest, youngest;

int main() {
    int n, count = 0, year, month, day, time;
    char name[5];
    oldest.time = 20140906;
    youngest.time = 18140906;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", name, &year, &month, &day);
        time = year * 10000 + month * 100 + day;
        if (isReasonable(time)) {
            count++;
            if (time < oldest.time) {
                oldest.time = time;
                oldest.name = name;
            }

            if (time > youngest.time) {
                youngest.time = time;
                youngest.name = name;
            }
        }
    }

    if (count == 0) {
        cout << 0;
    } else {
        cout << count << " " << oldest.name << " " << youngest.name << endl;
    }
    return 0;
}
