#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map <string, int> map;
    set<string> num (gems.begin(), gems.end());
    int min, start = 0, end = 0;
    
    for (auto& s : gems) {
        map[s]++;
        if (map.size() == num.size()) break;
        end++;
    }
    
    min = end - start;
    answer[0] = start + 1;
    answer[1] = end + 1;
    
    while (end < gems.size()) {
        string key = gems[start];
        map[key]--; start++;
        
        if (map[key] == 0) {
            end++;
            for (; end < gems.size(); end++) {
                map[gems[end]]++;
                if (key == gems[end]) break;
            }
            if (end == gems.size()) break;
        }
        
        if (min > end - start){
            answer[0] = start + 1;
            answer[1] = end + 1;
            min = end - start;
        }
    }

    return answer;
}