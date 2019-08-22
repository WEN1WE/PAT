/*
 * 1. for each 不能用来赋值, 想要赋值，要加引用 // for (auto & e : students)
 * 2. round(1.6) // 进行四舍五入，在 #include <cmath> 中
 * 3. 题目是对最终成绩进行筛选，而不是期末成绩
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Student {
    string name;
    int online = -1;
    int midterm = -1;
    int final = -1;
    int grade = -1;
};

bool cmp(Student s1, Student s2) {
    return s1.grade == s2.grade ? s1.name < s2.name : s1.grade > s2.grade;
}

int main() {
    int p, m, n;
    string name;
    cin >> p >> m >> n;
    map<string, Student> mp;
    vector<Student> students;
    
    for (int i = 0; i < p; i++) {
        cin >> name;
        mp[name].name = name;
        cin >> mp[name].online;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> name;
        mp[name].name = name;
        cin >> mp[name].midterm;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> name;
        mp[name].name = name;
        cin >> mp[name].final;
    }
    
    for (auto & e : mp) {
        if (e.second.midterm > e.second.final) {
            e.second.grade = round(e.second.midterm * 0.4 + e.second.final * 0.6);
        } else {
            e.second.grade = e.second.final;
        }
        
        if (e.second.online >= 200 && e.second.grade >= 60 && e.second.grade <= 100) {
            students.push_back(e.second);
        }
    }
    
    sort(students.begin(), students.end(), cmp);
    
    for (auto e : students) {
        printf("%s %d %d %d %d\n", e.name.c_str(), e.online, e.midterm, e.final, e.grade);
    }

    return 0;
}
