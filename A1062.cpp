/*
 * 1. 使用vector存信息的时候，可以使用.begin(), .end(), 结合sort, 很方便
 * 2. 本题考察的主要是对结构体sort
 * 3. 结构体里面加一个level, 会使代码简洁很多
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    string id;
    int virtue;
    int  talent;
    int level;
};

int judge(int virtue, int talent, int L, int H) {
    if (virtue >= H && talent >= H) {
        return 4;
    } else if (virtue >= H && talent >= L) {
        return 3;
    } else if (virtue >= L && talent >= L) {
        if (virtue >= talent) {
            return 2;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

bool cmp(Student s1, Student s2) {
    int total1 = s1.virtue + s1.talent;
    int total2 = s2.virtue + s2.talent;
    if (s1.level == s2.level) {
        if (total1 == total2) {
             if (s1.virtue == s2.virtue) {
                 return s1.id < s2.id;
             } else {
                 return s1.virtue > s2.virtue;
             }
        } else {
            return total1 > total2;
        }
    } else {
        return s1.level > s2.level;
    }
}

int main() {
    int N, L, H, count = 0;
    cin >> N >> L >> H;
    vector<Student> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].id >> students[i].virtue >> students[i].talent;
        students[i].level = judge(students[i].virtue, students[i].talent, L, H);
        if (students[i].level) {
            count++;
        }
    }

    sort(students.begin(), students.end(), cmp);

    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << students[i].id << " " << students[i].virtue << " " << students[i].talent << endl;
    }
    return 0;
}
