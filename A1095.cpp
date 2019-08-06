/*
 * 1. strcpy(str1, str2) // 将str2复制到str1
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>;
using namespace std;

struct Car {
    char plate[10];
    int time;
    int hh;
    int mm;
    int ss;
    string status;
};

bool cmp(Car car1, Car car2) {
    return strcmp(car1.plate, car2.plate) == 0 ? car1.time < car2.time : strcmp(car1.plate, car2.plate) < 0;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<Car> carsTemp(N);
    vector<Car> cars;

    for (int i = 0; i < N; i++) {
        scanf("%s %d:%d:%d", carsTemp[i].plate, &carsTemp[i].hh, &carsTemp[i].mm, &carsTemp[i].ss);
        cin >> carsTemp[i].status;
        carsTemp[i].time = carsTemp[i].hh * 3600 + carsTemp[i].mm * 60 + carsTemp[i].ss;
    }

    sort(carsTemp.begin(), carsTemp.end(), cmp);

    for (int i = 0; i < N; i++) {
        if (carsTemp[i].status != "in") {
            continue;
        }
        for (int j = i + 1; j < N; j++) {
            int d;
            if (strcmp(carsTemp[i].plate, carsTemp[j].plate) == 0 && carsTemp[j].status == "out") {
                cars.push_back(carsTemp[i]);
                cars.push_back(carsTemp[j]);
                i = j;
                break;
            }
            i = j - 1;
            break;
        }
    }

    int hh, mm, ss, time, count = 0;
    for (int i = 0; i < K; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        time = hh * 3600 + mm * 60 + ss;
        
        
    }
    return 0;
}
