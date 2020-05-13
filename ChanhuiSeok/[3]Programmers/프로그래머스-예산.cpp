#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int sizes;

/* 이분 탐색으로 특정 조건에 대한 최적해 구하기 */
/* 단순히 배열에서 특정 원소를 찾는 것이 아니고, 특정 조건일 때 최대 혹은 최소를 */
/* 구하는 데에도 사용될 수 있다. */

int solution(vector<int> budgets, int M) {

    sort(budgets.begin(), budgets.end()); // 오름차순 정렬

    int average = M / sizes;
    // 상한은 average로 보장이 되어 있다.
    // valid(x)가 x<=ANSWER 일 때는 true 고, x>ANSWER일 때 false이다.

    // average보다는 크지만 가장 작은 원소를 찾는다...
    int left = 0, right = budgets[budgets.size() - 1];
    int answer = 0;

    while (left <= right) {
        int num = 0;
        int k = (left + right) / 2; // 초기 - 75

        for (auto i : budgets) {
            if (k > i) { // budgets의 요소가 k(상한)보다 작으면, 결과값에 그 요소를 더한다.
                num += i;
            }
            else {
                num += k; // 상한보다 크면, k값을 더한다.
            }
        }

        // 총 더한값 num(즉, 찾고자 하는 값)이 M보다 작은지 큰지 파악해야 한다.
        if (num > M) { // M보다 컸으면, 상한을 줄일 필요가 있다.
            right = k - 1;
        }
        else {
            left = k + 1; // 상한을 늘리는 방향
            answer = k; // 더 늘리기 전 가능성 있는 답안
        }
    }

    return answer;
}