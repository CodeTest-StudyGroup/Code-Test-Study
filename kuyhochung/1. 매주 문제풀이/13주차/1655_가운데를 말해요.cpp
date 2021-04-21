#include <iostream>
#include <queue>

using namespace std;
#define MAX_N 100001

int N, temp;
int numbers[MAX_N];
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int> > minPQ;               //최소 힙, 최대 힙

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (minPQ.size() == maxPQ.size())
            maxPQ.push(temp);
        else if (minPQ.size() + 1 == maxPQ.size())
            minPQ.push(temp);
        if (!minPQ.empty() && !maxPQ.empty() && minPQ.top() < maxPQ.top()) {
            int mintemp, maxtemp;
            mintemp = minPQ.top();
            maxtemp = maxPQ.top();
            minPQ.pop();
            maxPQ.pop();
            minPQ.push(maxtemp);
            maxPQ.push(mintemp);
        }
        cout << maxPQ.top() << '\n';
    }
    
    return 0;
}
