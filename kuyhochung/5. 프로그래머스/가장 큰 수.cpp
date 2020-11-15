#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector <pair <int, int> > compare;
    
    for (int i = 0; i < numbers.size(); i++) {
        int original = numbers[i];
        while (numbers[i] < 1000 && numbers[i] != 0) {
            if (numbers[i] < 10) {
                numbers[i] = numbers[i] * 10 + numbers[i];
            }
            else if (numbers[i] < 100) {
                numbers[i] = numbers[i] * 100 + numbers[i];
            }
            else {
                numbers[i] = numbers[i]*10 + numbers[i]/100;
            }
        }
        compare.push_back(make_pair(numbers[i], original));
    }
    sort(compare.begin(),compare.end());
    
    while(!compare.empty()) {
        if (answer == "0" && compare.back().second == 0) {
            compare.pop_back();
            continue;
        }
        answer += to_string(compare.back().second);
        compare.pop_back();
    }
    
    return answer;
}