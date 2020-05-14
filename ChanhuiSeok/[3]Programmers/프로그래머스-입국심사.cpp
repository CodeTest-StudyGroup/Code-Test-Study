#define _CRT_SECURE_NO_WARNINGS

#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int sizes, M;

bool valid(int x, vector<int> budgets) {
    int sum = 0;
    for (int i = 0; i < budgets.size(); i++) {
        if (budgets[i] <= x)
            sum += budgets[i];
        else
            sum += x;
    }
    if (sum <= M)
        return true;
    else
        return false;
}

int main() {
    
    long long answer = 0;
    int n = 6;
    vector<int> times = { 7,10 };

    sort(times.begin(), times.end());

    // 처리해야 하는 작업의 개수 -> 사람의 수 -> n

    long long left, right;
    left = 1;
    right = times[times.size() - 1] * n;
    // 1분부터, 가장 느린 심사관이 모든 사람을 검사하는데 걸리는 시간이 맨 끝값으로
    // 이분 탐색 시작

    while (left <= right) {

        long long sum = 0;
        long long k = (left + right) / 2;

        for (int i = 0; i < times.size(); i++) {
            sum += k / times[i];
            // k 만큼의 시간동안 심사관 i가 검사할 수 있는 사람의 수 -> k / times[i]
        }

        // 그 합이, 검사해야 하는 사람의 수 n보다 작다면
        // left 값을 k + 1로 바꾼다.
        if (sum < n) {
            left = k + 1;
        }
        else {
            answer = k;
            right = k - 1;
        }
    }
    


    return 0;
}