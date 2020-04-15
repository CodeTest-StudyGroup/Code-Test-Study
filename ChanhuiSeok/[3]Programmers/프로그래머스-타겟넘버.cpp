#include <string>
#include <vector>

using namespace std;

vector<int> numbers;
int temp_target;
int answer;

void dfs(int depth, int sum, int cnt, vector<int> numbers, int target) {

    // 안에 있는 원소 갯수와 같아지면 확인
    if (depth >= numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }

    dfs(depth + 1, sum + numbers[cnt], cnt + 1, numbers, target);
    dfs(depth + 1, sum - numbers[cnt], cnt + 1, numbers, target);

}

int solution(vector<int> numbers, int target) {

    int depth = 0;
    dfs(depth, 0, 0, numbers, target);

    return answer;
}