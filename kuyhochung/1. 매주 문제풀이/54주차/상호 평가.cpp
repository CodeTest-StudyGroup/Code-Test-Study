#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char grade (int score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

int get_score (int self_index, vector<vector<int> > scores) {
    int self = scores[self_index][self_index];
    
    //해당 인원을 평가한 점수들을 grades에 옮김
    vector<int> grades;
    for (int i = 0; i < scores.size(); i++) {
        grades.push_back(scores[i][self_index]);
    }
    sort(grades.begin(), grades.end());
    
    //자기 자신을 평가한 점수가 최고점 또는 최저점인 경우
    if (grades[0] == self || grades.back() == self) {
        int count = 0;
        for (auto next : grades) {
            if (self == next) count++;
        }
        //유일한 최고점 또는 최저점인 경우
        if (count == 1) {
            if (grades[0] == self) {
                grades.erase(grades.begin());
            }
            else if (grades.back() == self) {
                grades.pop_back();
            }
        }
    }
    int sum = 0;
    for (auto next : grades) {
        sum += next;
    }
    sum /= grades.size();

    return sum;
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    for (int i = 0; i < scores.size(); i++) {
        answer += grade(get_score(i, scores));
    }
    return answer;
}