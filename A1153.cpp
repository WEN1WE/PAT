/*
 * 1. 本题容易超时，STL 的使用尽量使用引用
 * 
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


struct Student {
    string card;
    int score;
};

struct Type3 {
    string site;
    int count;
};

bool cmp(Student & s1, Student & s2) {
    return s1.score == s2.score ? s1.card < s2.card : s1.score > s2.score;
}

bool cmp2(Type3 & t1, Type3 & t2) {
    return t1.count == t2.count ? t1.site < t2.site : t1.count > t2.count;
}

int main() {
    int N, M, score, type;
    string term;
    string s;
    scanf("%d %d", &N, &M);
    vector<Student> record(N);

    for (int i = 0; i < N; i++) {
        cin >> record[i].card >> record[i].score;
    }

    for (int i = 1; i <= M; i++) {
        vector<Student> result;
        vector<Type3> result2;
        cin >> type >> term;
        printf("Case %d: %d %s\n", i, type, term.c_str());

        if (type == 1) {
            for (auto & e : record) {
                if (e.card[0] == term[0]) {
                    result.push_back(e);
                }
            }
            if (result.empty()) {
                printf("NA\n");
            } else {
                sort(result.begin(), result.end(), cmp);
                for (auto & e : result) {
                    printf("%s %d\n", e.card.c_str(), e.score);
                }
            }
        }

        if (type == 2) {
            int totalNumber = 0;
            int totalScore = 0;
            for (auto & e : record) {
                if (e.card.substr(1, 3) == term) {
                    totalNumber++;
                    totalScore += e.score;
                }
            }
            if (totalNumber == 0) {
                printf("NA\n");
            } else {
                printf("%d %d\n", totalNumber, totalScore);
            }
        }

        if (type == 3) {
            map<string, int> mp;
            for (auto & e : record) {
                if (e.card.substr(4, 6) == term) {
                    mp[e.card.substr(1, 3)]++;
                }
            }
            if (mp.empty()) {
                printf("NA\n");
            } else {
                for (auto & e : mp) {
                    result2.push_back({e.first, e.second});
                }
                sort(result2.begin(), result2.end(), cmp2);
                for (auto & e : result2) {
                    printf("%s %d\n", e.site.c_str(), e.count);
                }
            }
        }
    }
    return 0;
}
