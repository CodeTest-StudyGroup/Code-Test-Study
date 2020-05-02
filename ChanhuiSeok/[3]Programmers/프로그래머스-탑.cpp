#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> stk;
    bool pushFlag = false;

    for (int i = heights.size() - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (heights[j] > heights[i]) {
                stk.push(j + 1);
                pushFlag = true;
                break;
            }
        }
        if (!pushFlag)
            stk.push(0);
        pushFlag = false;
    }
    while (!stk.empty()) {
        answer.push_back(stk.top());
        stk.pop();
    }
    return answer;
}