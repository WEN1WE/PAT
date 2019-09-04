/*
 * 1. for each 不能用来赋值, 想要赋值，要加引用 // for (auto & e : students)
 * 2. round(1.6) // 进行四舍五入，在 #include <cmath> 中
 * 3. 题目是对最终成绩进行筛选，而不是期末成绩
 */

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct Student {
    string id;
    int online = -1;
    int midterm = -1;
    int final = -1;
    int grade = -1;
};

bool check(Student & s) {
    if (s.online < 200 || s.online > 900) {
        return false;
    } else {
        if (s.midterm > s.final) {
            s.grade = int(round(0.4 * s.midterm + 0.6 * s.final));
        } else {
            s.grade = s.final;
        }
        return s.grade >= 60;
    }
}

bool cmp(Student & s1, Student & s2) {
    if (s1.grade != s2.grade) {
        return s1.grade > s2.grade;
    } else {
        return s1.id < s2.id;
    }
}

int main() {
    int P, M, N;
    scanf("%d %d %d", &P, &M, &N);
    int score;
    string id;
    map<string, Student> mp;
    vector<Student> result;

    for (int i = 0; i < P; i++) {
        cin >> id >> score;
        mp[id].id = id;
        mp[id].online = score;
    }
    for (int i = 0; i < M; i++) {
        cin >> id >> score;
        mp[id].id = id;
        mp[id].midterm = score;
    }
    for (int i = 0; i < N; i++) {
        cin >> id >> score;
        mp[id].id = id;
        mp[id].final = score;
    }

    for (auto e : mp) {
        if (check(e.second)) {
            result.push_back(e.second);
        }
    }
    sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < result.size(); i++) {
        printf("%s %d %d %d %d\n", result[i].id.c_str(), result[i].online, result[i].midterm, result[i].final, result[i].grade);
    }
    return 0;
}
