#include <string>
#include <vector>
#include <cmath>

using namespace std;

int get_distance (int start, int to) {
    int to_row = to / 3;
    int to_column = to % 3;
    
    int start_row = start / 3;
    int start_column = start % 3;
    
    return (abs(start_row - to_row) + abs(start_column - to_column));
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left = 9, right = 11;
    
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) numbers[i] = 10;
        else numbers[i]--;
        if (numbers[i] % 3 == 0) {
            answer += "L";
            left = numbers[i];
        }
        else if (numbers[i] % 3 == 2) {
            answer += "R";
            right = numbers[i];
        }
        else if (numbers[i] % 3 == 1) {
            int leftDist = get_distance(left, numbers[i]);
            int rightDist = get_distance(right, numbers[i]);
            
            if (leftDist < rightDist) {
                answer += "L";
                left = numbers[i];
            }
            else if (leftDist > rightDist) {
                answer += "R";
                right = numbers[i];
            }
            else if (leftDist == rightDist) {
                if (hand == "left") {
                    answer += "L";
                    left = numbers[i];
                }
                else if (hand == "right") {
                    answer += "R";
                    right = numbers[i];
                }
            }
        }
    }
    
    return answer;
}