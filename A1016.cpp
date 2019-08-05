/*
 * 1. 使用cmp 是， 可以两个条件同时用，这样代码会简短
 * 2. 读入数据的时候，对输入直接进行处理，代码也会简短
 * 3. 当程序想传出多个值时，使用struct
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Record {
    string name;
    string time;
    string word;
};

struct Result {
    string month;
    int totalMinutes;
    double money;
};

Result charge(string time1, string time2, int rate[]) {
    int day1, day2, hour1, hour2, minute1, minute2;
    int totalMinutes = 0;
    int sum = 0;
    day1 = stoi(time1.substr(3, 2));
    hour1 = stoi(time1.substr(6, 2));
    minute1 = stoi(time1.substr(9));

    day2 = stoi(time2.substr(3, 2));
    hour2 = stoi(time2.substr(6, 2));
    minute2 = stoi(time2.substr(9));

    while (!(day1 == day2 && hour1 == hour2 && minute1 == minute2)) {
        totalMinutes++;
        sum += rate[hour1];
        if (++minute1 == 60) {
            minute1 = 0;
            if (++hour1 == 24) {
                hour1 = 0;
                day1++;
            }
        }
    }
    Result result = {time1.substr(0, 2), totalMinutes, sum / 100.0};
    return result;
}

bool cmpName(Record record1, Record record2) {
    return record1.name < record2.name;
}

bool cmpTime(Record record1, Record record2) {
    return record1.time < record2.time;
}

int main() {
    int n, rate[24];
    int count = 1;
    int endIndex[1000] = {0};

    for (int & e : rate) {
        cin >> e;
    }
    cin >> n;
    vector<Record> records(n);

    for (int i = 0; i < n; i++) {
        cin >> records[i].name >> records[i].time >> records[i].word;
    }

    sort(records.begin(), records.end(), cmpName);

    for (int i = 1; i < records.size(); i++) {
        if (records[i].name != records[i - 1].name) {
            endIndex[count++] = i;
        }
    }
    endIndex[count] = n;   // endIndex = [0, 2, 6, 10]

    for (int i = 0; i < count; i++) {
        sort(records.begin() + endIndex[i], records.begin() + endIndex[i + 1], cmpTime);
    }

    for (int i = 0; i < count; i++) {
        int flag = false;
        int flag2 = true;
        string timeStart, timeEnd;
        double totalAmount = 0.0;
        Result result;

        for (int j = endIndex[i]; j < endIndex[i + 1]; j++) {
            if (records[j].word == "on-line") {
                flag = true;
                timeStart = records[j].time;
            }
            if (records[j].word == "off-line" && flag) {
                flag = false;
                timeEnd = records[j].time;
            }
            if (timeStart.length() && timeEnd.length()) {
                result = charge(timeStart, timeEnd, rate);
                if (flag2) {
                    cout << records[j].name << " " << result.month << endl;
                    flag2 = false;
                }
                totalAmount += result.money;
                printf("%s %s %d $%.2f\n", timeStart.substr(3).c_str(), timeEnd.substr(3).c_str(), result.totalMinutes, result.money);
                flag = false;
                timeStart = "";
                timeEnd = "";
            }
        }
        if (totalAmount != 0) {
            printf("Total amount: $%.2f\n", totalAmount);
        }
    }
    return 0;
}
