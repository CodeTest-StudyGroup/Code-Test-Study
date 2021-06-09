#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
long long answer = 0;
char preset[3] = {'+', '-', '*'};

void calculate (vector<long long> numbers, vector<char> opers, int operSelect, vector<int> visited) {
    
    char now = preset[operSelect];
    for (int i = 0; i < opers.size(); i++) {
        if (opers[i] == now) {
            opers.erase(opers.begin() + i);
            if (operSelect == 0) {
                numbers[i+1] += numbers[i];
            }
            else if (operSelect == 1) {
                long long temp = (numbers[i] - numbers[i+1]);
                numbers[i+1] = temp;
            }
            else if (operSelect == 2) {
                numbers[i+1] *= numbers[i];
            }
            numbers.erase(numbers.begin() + i);
            i--;
        }
    }
    
    visited[operSelect]++;
    visited[3]++;
    if (visited[3] == 3) {
        answer = max(answer, abs(numbers[0]));
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (visited[i] == 1) continue;
            calculate(numbers, opers, i, visited);
        }
    }
}

long long solution(string expression) {
    
    vector<long long> numbers;
    vector<char> opers;
    
    string temp = "";
    for (int i = 0; i < expression.size(); i++) {
        if ((expression[i] != '*') && (expression[i] != '+') && (expression[i] != '-')) {
            temp += expression[i];
        }
        else {
            
            numbers.push_back(stoll(temp));;
            opers.push_back(expression[i]);
            temp = "";
        }
    }
    numbers.push_back(stoll(temp));
    
    vector<int> visited = {0, 0, 0, 0};
    for (int i = 0; i < 3; i++) {
        calculate(numbers, opers, i, visited);
    }
    
    return answer;
}