#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    answer.clear();
    vector <int> store;

    for (int i = 0; i < operations.size(); i++) {
        string now = operations[i];
        istringstream ss(now);
        string buffer;
        vector<string> result;
        result.clear();

        while (getline(ss, buffer, ' ')) {
            result.push_back(buffer);
        }

        int currentVal = stoi(result[1]);

        
        if (result[0][0] == 'I') {
            store.push_back(currentVal);
        }
        
        else if (result[0][0] == 'D') {
            if (store.empty()) continue;
            if (currentVal == 1) {
                sort(store.begin(), store.end());
                store.pop_back();
            }
            else if (currentVal == -1) {
                sort(store.begin(), store.end(), greater<>());
                store.pop_back();
            }
        }
    }

    if (!store.empty()) {
        sort(store.begin(), store.end());
        answer.push_back(store.back());
        answer.push_back(store[0]);
    }

    vector<int> emptyResult = { 0, 0 };
    if (answer.empty()) return emptyResult;
    else return answer;
}
