/*
 * 1. double精确到小数点后两位，会自己四舍五入
 * 2. 这个题目从第一个加油站设计贪心算法，如果从全局来看，设计太过复杂
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Station {
    double price;
    double distance;
};

bool cmp(Station s1, Station s2) {
    return s1.distance < s2.distance;
}

int main() {
    int n, currentStation = 0;
    double capacity, totalDistance, average, totalPrice = 0, rest = 0;
    double maxDistancePerFill;
    scanf("%lf %lf %lf %d", &capacity, &totalDistance, &average, &n);
    vector<Station> stations(n + 1);
    maxDistancePerFill = capacity * average;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &stations[i].price, &stations[i].distance);
    }
    stations[n].price = 0;
    stations[n].distance = totalDistance;
    sort(stations.begin(), stations.end(), cmp);

    if (stations[0].distance != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    while (currentStation < n) {
        bool flag1 = false;
        bool flag2 = false;
        int tempStation = -1;
        double lowestPrice = 1000000;
        double d = 0;
        for (int i = currentStation + 1; i < n + 1; i++) {
            d = stations[i].distance - stations[currentStation].distance;
            if (d <= capacity * average) {
                flag1 = true;
                if (stations[i].price < stations[currentStation].price) {
                    totalPrice += (d - rest) * stations[currentStation].price / average;
                    flag2 = true;
                    rest = 0;
                    currentStation = i;
                    break;
                }
                if (stations[i].price < lowestPrice) {
                    tempStation = i;
                    lowestPrice = stations[i].price;
                }
            } else {
                break;
            }
        }
        if (!flag1) {
            printf("The maximum travel distance = %.2f", stations[currentStation].distance + maxDistancePerFill);
            break;
        }
        if (!flag2) {
            totalPrice += (maxDistancePerFill - rest) * stations[currentStation].price / average;
            d = stations[tempStation].distance - stations[currentStation].distance;
            rest = maxDistancePerFill - d;
            currentStation = tempStation;
        }
    }

    if (currentStation == n) {
        printf("%.2f", totalPrice);
    }
    return 0;
}
