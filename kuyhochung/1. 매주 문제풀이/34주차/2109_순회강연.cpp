#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int d = -1;
vector <pair <int, int> > lectures;
int answer = 0;

bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int cost, days;
        cin >> cost >> days;
        lectures.push_back({cost, days});
        d = max(d, days);
    }
    
    sort(lectures.begin(), lectures.end(), cmp);
    
    priority_queue<int> pq;
    int lectureIndex = 0;
    for (; d >= 1; d--) {
        while(lectureIndex < n && d <= lectures[lectureIndex].second) {
            pq.push(lectures[lectureIndex++].first);
        }
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }
    
    cout << answer;
    
    return 0;
}
