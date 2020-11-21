#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
#define MAX_K 101
int K, N;
vector<int> primes;
priority_queue<int, vector<int>, greater<int>> pq;
//값이 낮을수록 priority queue의 우선순위가 높도록 함

int main() {
    
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        primes.push_back(tmp);
        pq.push(tmp);
    }
    
    for (int i = 0; i < N-1; i++) {
        long long top = pq.top();
        for (int j = 0; j < K; j++) {
            long long tmp = top*primes[j];
            if (tmp < pow(2,31))
                pq.push(tmp);
        }
        while(pq.top() == top)
            pq.pop();
    }
    
    cout << pq.top();
    
    return 0;
}
