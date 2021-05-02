#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int timePassed = 1e9;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.first <= timePassed && b.first <= timePassed) {
            if (a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        }
        else {
            return a.first > b.first;
        }
    }
};

priority_queue< pair <int, int>, vector<pair <int, int> >,  cmp > jobs;

int solution(vector<vector<int>> jobsInput) {
    int answer = 0;
    
    for (int i = 0; i < jobsInput.size(); i++) {
        timePassed = min(timePassed, jobsInput[i][0]);
    }
    
    for (int i = 0; i < jobsInput.size(); i++) {
        jobs.push({jobsInput[i][0], jobsInput[i][1]});
    }

    int n = (int)jobs.size();
    
    while(!jobs.empty()) {
        int enterTime = jobs.top().first;
        int costTime = jobs.top().second;
        
        if (timePassed < enterTime) {
            timePassed++;
            continue;
        }
        answer += (costTime + (timePassed - enterTime));
        
        timePassed += costTime;
        jobs.pop();
        
        vector<pair<int, int> > buffer;
        while(!jobs.empty()) {
            buffer.push_back({jobs.top().first, jobs.top().second});
            jobs.pop();
        }
        while(!buffer.empty()) {
            jobs.push({buffer.back().first, buffer.back().second});
            buffer.pop_back();
        }
    }

    answer /= n;
    return answer;
}