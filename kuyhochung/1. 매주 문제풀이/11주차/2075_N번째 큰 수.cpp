#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int N;
priority_queue <int, vector<int>, greater<int> > pq;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N*N; i++) {
        int temp;
        cin >> temp;
        if (pq.size() < N)
            pq.push(temp);
        else if (pq.top() < temp) {
            pq.pop();
            pq.push(temp);
        }
    }
    cout << pq.top();
    return 0;
}
