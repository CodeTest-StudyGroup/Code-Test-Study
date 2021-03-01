#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int n = answer;
    
    for (int i = 1; i < n/2 + 1; i++) {
        string now = "";
        string previous = s.substr(0, i);
        int count = 1;
        for (int j = i; j < n; j += i) {
            if (previous == s.substr(j, i))
                count++;
            else {
                if (count >= 2)
                    now += to_string(count);
                now += previous;
                previous = s.substr(j, i);
                count = 1;
            }
        }
        
        if (count >= 2)
            now += to_string(count);
        now += previous;
    
        answer = min(answer, (int)(now.size()));
    }
    return answer;
}
