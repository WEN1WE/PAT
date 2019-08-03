#include <iostream>
using namespace std;

struct student {
    string name;
    char gender;
    string ID;
    int grade;
} femaleHighest, maleLowest;

int main() {
    int n, grade;
    char gender;
    string name, ID;
    cin >> n;

    femaleHighest.name = "Absent";
    femaleHighest.grade = 0;

    maleLowest.name = "Absent";
    maleLowest.grade = 100;

    for (int i = 0; i < n; i++) {
        cin >> name >> gender >> ID >> grade;
        if (gender == 'F') {
            if (grade > femaleHighest.grade) {
                femaleHighest.name = name;
                femaleHighest.grade = grade;
            }
        } else{
            if (grade < maleLowest.grade) {
                maleLowest.name = name;
                maleLowest.grade = grade;
            }
        }
    }

    if (maleLowest.name == "Absent" || female)
}
