/*
 * 1. 本题可使用二分查找或two points
 * 2. upper_bound, lower_bound的使用
 *  lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
 *  upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
 * 3. 本题不能使用j--
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, maxNumbers = 0, temp;
    long long p;
    scanf("%d %lld", &N, &p);
    vector<long long>  numbers(N);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &numbers[i]);
    }
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i + maxNumbers < N; i++) {
        for (int j = maxNumbers + i; j < N; j++) {
            if (numbers[j] <= p * numbers[i]) {
                maxNumbers = max(j - i + 1, maxNumbers);
            } else {
                break;
            }
        }
    }
    cout << maxNumbers;
    return 0;
}
