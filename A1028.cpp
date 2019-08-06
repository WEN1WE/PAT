/*
 * 1. string 可以用 == 来表示相等 "acc" == "acc"
 * 2. vector<Student> records(n); // 初始化使用的是()
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int COLUMN;

struct Student {
    string info[3];
};

bool cmp(Student s1, Student s2) {
    return s1.info[COLUMN] == s2.info[COLUMN] ? s1.info[0] < s2.info[0] : s1.info[COLUMN] < s2.info[COLUMN];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Student> records(n);
    COLUMN = k - 1;

    for (int i = 0; i < n; i++) {
        cin >> records[i].info[0] >> records[i].info[1] >> records[i].info[2];
    }
    sort(records.begin(), records.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << records[i].info[0] << " " << records[i].info[1] << " " << records[i].info[2] << endl;
    }
    return 0;
}
