/*
 * 1. 插入排序的写法
 * 2. 题目陷阱，不包含初始序列
 * 3. 归并排序的写法
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> initial(N);
    vector<int> partially(N);

    for (int i = 0; i < N; i++) {
        cin >> initial[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> partially[i];
    }

    int p, q;

    for (p = 0; p < N - 1 && partially[p] <= partially[p + 1]; p++);
    for (q = p + 1; q < N && initial[q] == partially[q]; q++);

    if (q == N) {
        printf("Insertion Sort\n");
        sort(initial.begin(), initial.begin() + p + 2);
    } else {
        printf("Merge Sort\n");
        int step = 2;
        bool flag = true;
        while (flag) {
            if (initial == partially) {
                flag = false;
            }
            for (int i = 0; i < N; i += step) {
                sort(initial.begin() + i, initial.begin() + min(N, i + step));
            }
            step *= 2;
        }
    }
    

    for (int i = 0; i < N; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", initial[i]);
    }
}


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool insertionSort(vector<int> & initial, vector<int> & partial) {
    bool flag = false;
    for (int i = 1; i < initial.size(); i++) {
        if (flag) {
            break;
        }

        if (i != 1 && partial == initial) {
            flag = true;
        }
        for (int j = i; j > 0; j--) {
            if(initial[j] < initial[j - 1]) {
                swap(initial[j], initial[j - 1]);
            } else {
                break;
            }
        }
    }
    return flag;
}

bool mergeSort(vector<int> & initial, vector<int> & partial) {
    bool flag = false;
    int N = initial.size();
    for (int step = 2; step / 2 <= N; step *= 2) {
        if (flag) {
            break;
        }

        if (step != 2 && initial == partial) {
            flag = true;
        }

        for (int i = 0; i < N; i += step) {
            sort(initial.begin() + i, initial.begin() + min(N, i + step));
        }
    }
    return flag;
}

void print(vector<int> & sequence) {
    for (int i = 0; i < sequence.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << sequence[i];
    }
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> initial(N);
    vector<int> partially(N);
    vector<int> tempInitial(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &initial[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &partially[i]);
    }

    tempInitial = initial;
    if (insertionSort(tempInitial, partially)) {
        printf("Insertion Sort\n");
        print(tempInitial);
        return 0;
    }

    tempInitial = initial;
    if (mergeSort(tempInitial, partially)) {
        printf("Merge Sort\n");
        print(tempInitial);
    }

    return 0;
}
