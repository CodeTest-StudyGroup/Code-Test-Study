#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool pass(int x, int k, vector<int>& stones) {
    int cnt = 0;
    for (auto stone : stones) {
        if (stone < x) {
            cnt++;
            if (cnt >= k) return false;
        } else {
            cnt = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    const auto [mn, mx] = minmax_element(stones.begin(), stones.end());
    int lo = *mn, hi = *mx;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (pass(mid, k, stones)) {
            answer = max(answer, mid);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return answer;
}

int main() {
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    cout << solution(stones, k) << endl;
    return 0;
}