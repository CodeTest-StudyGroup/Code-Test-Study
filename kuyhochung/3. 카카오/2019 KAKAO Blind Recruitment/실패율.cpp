//https://programmers.co.kr/learn/courses/30/lessons/42889

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<double, int> &a, const pair <double, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    int total_users = stages.size();
    vector <pair <double, int> > fail_rate;
    
    for (int i = 1; i <= N; i++) {
        int cnt = count(stages.begin(), stages.end(), i);
        
        double fail = 0;
        if (total_users >= 1) {
            fail = (double) cnt / total_users;
        }
        
        fail_rate.push_back(make_pair(fail, i));
        total_users -= cnt;
    }
    
    sort(fail_rate.begin(), fail_rate.end(), cmp);
    
    vector<int> answer;
    for (int i = 0; i < N; i++) {
        answer.push_back(fail_rate[i].second);
    }
    
    return answer;
}
