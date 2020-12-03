#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#define MIN 8

int basicNum(int N, int cnt) {
    int number = 0;
    
    while (cnt > 0) {
        cnt -= 1;
        number += N * pow(10, cnt);
    }
    
    return number;
}

int solution(int N, int number) {
    if (N == number) {
        return 1;
    }
    int answer = -1;
    
    auto s = vector<set<int>>(MIN);

    int idx = 1;
    for (auto & x : s) {
        x.insert(basicNum(N, idx));
        idx += 1;
    }

    for (int i = 1; i < MIN; i++) {
        for (int j = 0; j < i; j++) {
            for (const auto & set1 : s[j]) {
                for (const auto & set2 : s[i-j-1]) {
                    s[i].insert(set1 + set2);
                    s[i].insert(set1 - set2);
                    s[i].insert(set1 * set2);
                    if (set2 != 0)
                        s[i].insert(set1 / set2);
                }
            }
        }
        
        if (s[i].find(number) != s[i].end()) {
            answer = i+1;
            break;
        }
    }
    
    return answer;
}
