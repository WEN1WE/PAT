/*
 * 1. 此问题为贪心问题，最大的正数与最大的正数相乘，最大的负数与最大的负数相乘
 * 2. 当程序写起来麻烦，使用两次sort有时候变简单
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int nc, np;
    int temp;
    long long result = 0;
    vector<int> vc, vp;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++) {
        scanf("%d", &temp);
        vc.push_back(temp);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &temp);
        vp.push_back(temp);
    }

    sort(vc.begin(), vc.end(), cmp);
    sort(vp.begin(), vp.end(), cmp);
    for (int i = 0; i < vc.size(); i++) {
        if (i < vp.size() && vc[i] > 0 && vp[i] > 0) {
            result += vc[i] * vp[i];
        }
    }

    sort(vc.begin(), vc.end());
    sort(vp.begin(), vp.end());
    for (int i = 0; i < vc.size(); i++) {
        if (i < vp.size() && vc[i] < 0 && vp[i] < 0) {
            result += vc[i] * vp[i];
        }
    }

    printf("%lld", result);
    return 0;
}
