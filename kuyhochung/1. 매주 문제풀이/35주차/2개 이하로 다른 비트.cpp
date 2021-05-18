#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int n = (int)numbers.size();
    for(int i = 0; i < n; i++){
        long long number = numbers[i];
        if (number % 2 == 0) {
            answer.push_back(number + 1);
        } else {
            // 최하위 비트
            unsigned long long lastBit = ~number & (number + 1);
            answer.push_back((number | lastBit) & ~(lastBit >> 1));
        }
    }
    return answer;
}