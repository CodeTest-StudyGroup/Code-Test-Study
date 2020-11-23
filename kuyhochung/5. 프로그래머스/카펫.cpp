#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    vector<int> answer;
    for (int i = 3;; i++) {
        int temp = total / i;
        if (total % i == 0 && temp >= i && temp*2 + i*2 == brown + 4) {
            answer.push_back(temp);
            answer.push_back(i);
            break;
        }
    }
    return answer;
}