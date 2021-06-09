#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//문제의 수는 n개이다. i번째 문제의 난이도는 Ai이다.
//문제 난이도의 합은 l보다 크거나 같다.
//문제 난이도의 합은 r보다 작거나 같다.
//가장 쉬운 난이도와 어려운 난이도의 차는 x보다 크거나 같다.
int n, l, r, x;
vector<int> problems;
//2개 이상의 문제를 골라야 한다.

bool available(int min, int max, int sum) {
    if (l <= sum && sum <= r && (max-min) >= x) return true;
    else return false;
}

int cases = 0;

void choose (vector<int> remaining, vector<int> chosen) {
    
    for (int i = 0; i < remaining.size(); i++) {
        int target = remaining[i];
        
        int sum = target;
        for (int j = 0; j < chosen.size(); j++) {
            sum += chosen[j];
        }
        int minimum = min(chosen[0], target);
        int maximum = max(chosen.back(), target);
        
        if (available(minimum, maximum, sum)) {
            cases++;
        }
        vector<int> copied;
        vector<int> chosen2;
        copied.clear();
        copied.assign(remaining.begin() + i + 1, remaining.end());
        chosen2.clear();
        chosen2.assign(chosen.begin(), chosen.end());
        chosen2.push_back(target);
        sort(chosen2.begin(), chosen2.end());
            
        choose(copied, chosen2);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) {
        int difficulty;
        cin >> difficulty;
        problems.push_back(difficulty);
    }
    
    sort(problems.begin(), problems.end());
    
    for (int i = 0; i < problems.size() - 1; i++) {
        vector<int> copied;
        vector<int> chosen;
        
        chosen.push_back(problems[i]);
        copied.clear();
        copied.assign(problems.begin() + i + 1, problems.end());
        choose(copied, chosen);
    }

    cout << cases;
    return 0;
}