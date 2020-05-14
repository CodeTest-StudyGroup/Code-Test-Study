#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h_idx = -1;
    sort(citations.begin(), citations.end());

    for (int h = 0; h <= citations[citations.size() - 1]; h++) {
        int temp_h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h) {
                temp_h++;
            }
        }
        if (temp_h >= h)
            h_idx = h;
    }

    answer = h_idx;
    return answer;
}