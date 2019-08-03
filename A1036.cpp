/*
 * 1. 使用结构体来收集信息
 */

#include <iostream>
using namespace std;

struct student {
    string name;
    string ID;
    int grade;
} femaleHighest, maleLowest;

int main() {
    bool sign1 = false, sign2 = false;
    int n, grade;
    char gender;
    string name, ID;
    cin >> n;

    femaleHighest.grade = 0;
    maleLowest.grade = 100;

    for (int i = 0; i < n; i++) {
        cin >> name >> gender >> ID >> grade;
        if (gender == 'F') {
            sign1 = true;
            if (grade > femaleHighest.grade) {
                femaleHighest.name = name;
                femaleHighest.ID = ID;
                femaleHighest.grade = grade;
            }
        } else {
            sign2 = true;
            if (grade < maleLowest.grade) {
                maleLowest.name = name;
                maleLowest.ID = ID;
                maleLowest.grade = grade;
            }
        }
    }

    if (sign1) {
        cout << femaleHighest.name << " " << femaleHighest.ID << endl;
    } else {
        cout << "Absent" << endl;
    }

    if (sign2) {
        cout << maleLowest.name << " " << maleLowest.ID << endl;
    } else {
        cout << "Absent" << endl;
    }

    if (sign1 && sign2) {
        cout << femaleHighest.grade - maleLowest.grade;
    } else {
        cout << "NA";
    }
    return 0;
}
