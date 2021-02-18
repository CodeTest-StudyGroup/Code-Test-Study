#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long n = food_times.size();
    long long extra_variable = 0;
    
    //전체 음식을 먹기 위해 소요되는 시간
    for (int i = 0; i < n; i++)
        extra_variable += food_times[i];
    if (extra_variable <= k) return -1;
    
    priority_queue< pair <int, int> > pq;
    for (int i = 0; i < n; i++)
        pq.push(make_pair(-food_times[i], i+1));
    
    extra_variable = 0;             //먹기 위해 사용한 시간
    long long previous_foods = 0;
    
    long long until_now = extra_variable + (-pq.top().first - previous_foods) * n;
    while (until_now <= k) {
        int now = -pq.top().first;
        pq.pop();
        extra_variable += (now - previous_foods) * n;
        n--;
        previous_foods = now;
        until_now = extra_variable + (-pq.top().first - previous_foods) * n;
    }
    
    vector <pair <int, int> > result;
    while (!pq.empty()) {
        int time_now = -pq.top().first;
        int food_now = pq.top().second;
        pq.pop();
        result.push_back(make_pair(food_now, time_now));
    }
    
    sort(result.begin(), result.end());
    answer = result[(k - extra_variable) % n].first;
    
    return answer;
}
