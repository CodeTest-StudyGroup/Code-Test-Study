#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int count) {
    if (count == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    
    dfs(numbers, target, sum + numbers[count], count+1);
    dfs(numbers, target, sum - numbers[count], count+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}