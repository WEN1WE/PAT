/*
 * 1. 本题数据量大，效率问题
 * 2. 题目到最后再对分数进行取整
 * 3. 如果运行时出错，一般为越界问题
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Institution {
    int rank;
    string school;
    int TWS = 0;
    int Ns = 0;
    double total;
};

bool cmp(Institution & s1, Institution & s2) {
    if (s1.TWS != s2.TWS) {
        return s1.TWS > s2.TWS;
    } else if (s1.Ns != s2.Ns) {
        return s1.Ns < s2.Ns;
    } else {
        return s1.school < s2.school;
    }
}

double getScore(char type, int score) {
    if (type == 'A') {
        return score;
    } else if (type == 'T') {
        return 1.5 * score;
    } else {
        return score / 1.5;
    }
}

void toLower(string & s) {
    for (auto & c : s) {
        c = tolower(c);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    map<string, Institution> mp;
    vector<Institution> institutions;
    
    for (int i = 0; i < n; i++) {
        string id, school;
        int score;
        cin >> id >> score >> school;
        toLower(school);
        mp[school].school = school;
        mp[school].Ns++;
        mp[school].total += getScore(id[0], score);
    }
    
    for (auto & e : mp) {
        e.second.TWS = e.second.total;
        institutions.push_back(e.second);
    }
    
    sort(institutions.begin(), institutions.end(), cmp);
    
    institutions[0].rank = 1;
    for (int i = 1; i < institutions.size(); i++) {
        if (institutions[i].TWS == institutions[i - 1].TWS) {
            institutions[i].rank = institutions[i - 1].rank;
        } else {
            institutions[i].rank = i + 1;
        }
    }
    
    printf("%d\n", institutions.size());
    for (auto & e : institutions) {
        printf("%d %s %d %d\n", e.rank, e.school.c_str(), e.TWS, e.Ns);
    }
    
    return 0;
}
