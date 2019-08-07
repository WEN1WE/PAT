/*
 * 1. strcpy(str1, str2) // 将str2复制到str1
 * 2. 使用string 来接收数据，操作方便
 * 3. char *cStr = "C++"; std::string Str = std::string(cStr);  //char * to string
 * 4. map mp; mp.first; mp.second;
 * 5. 本题主要的难点是时间，解决的方法是按照机械的方法数
 * 6. 本题也可以按照时间序把车子再拍一次，统计每个时刻的车子的数量
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Car {
    string plate;
    int time;
    int hh;
    int mm;
    int ss;
    string status;
};

struct Query {
    int time;
    int count = 0;
};

bool cmp(Car car1, Car car2) {
    return car1.plate == car2.plate ? car1.time < car2.time : car1.plate < car2.plate;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<Car> carsTemp(N);
    vector<Car> cars;
    vector<Query> queries(K);
    vector<string> longestCar;
    map<string, int> mp;

    for (int i = 0; i < N; i++) {
        cin >> carsTemp[i].plate;
        scanf("%d:%d:%d", &carsTemp[i].hh, &carsTemp[i].mm, &carsTemp[i].ss);
        cin >> carsTemp[i].status;
        carsTemp[i].time = carsTemp[i].hh * 3600 + carsTemp[i].mm * 60 + carsTemp[i].ss;
    }

    sort(carsTemp.begin(), carsTemp.end(), cmp);

    // 排序之后，in out 是相邻的
    for (int i = 0; i < N - 1; i++) {
        if (carsTemp[i].status == "in" && carsTemp[i].plate == carsTemp[i + 1].plate && carsTemp[i + 1].status == "out") {
            cars.push_back(carsTemp[i]);
            cars.push_back(carsTemp[i + 1]);
        }
    }

    int hh, mm, ss;
    for (int i = 0; i < K; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        queries[i].time = hh * 3600 + mm * 60 + ss;
    }

    int p = 0;
    string lastPlate;
    for (int i = 0; i < cars.size() - 1; i += 2) {
        if (cars[i].plate != lastPlate) {
            p = 0;
        }
        for (int j = p; j < K; j++) {
            if (queries[j].time > cars[i + 1].time) {
                p = j;
                break;
            }
            if (queries[j].time >= cars[i].time && queries[j].time < cars[i + 1].time) {
                queries[j].count++;
            }
        }
        lastPlate = cars[i].plate;

        if (mp.find(cars[i].plate) == mp.end()) {
            mp[cars[i].plate] = cars[i + 1].time - cars[i].time;
        } else {
            mp[cars[i].plate] += cars[i + 1].time - cars[i].time;
        }
    }

    int longestTime = 0;
    for (auto e : mp) {
        if (e.second > longestTime) {
            longestTime = e.second;
        }
    }

    for (auto e : mp) {
        if (e.second == longestTime) {
            longestCar.push_back(e.first);
        }
    }

    sort(longestCar.begin(), longestCar.end());
    
    for (int i = 0; i < K; i++) {
        cout << queries[i].count << endl;
    }
    for (auto e : longestCar) {
        cout << e << " ";
    }
    printf("%02d:%02d:%02d", longestTime / 3600, (longestTime % 3600) / 60, longestTime % 60);
    return 0;
}

/*
16 1
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
12:23:42
 */
