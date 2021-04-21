#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int N, sum;
priority_queue<int> positive;
priority_queue<int, vector<int>, greater<int> > negative;
int one_count = 0, zero_count = 0;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp == 1)
            one_count++;
        else if (temp > 0)
            positive.push(temp);
        else if (temp < 0)
            negative.push(temp);
        else if (temp == 0)
            zero_count++;
        else {
            cout << "error!";
            return 0;
        }
    }
    
    if (positive.size() % 2) {
        positive.push(1);
    }
    if (negative.size() % 2) {
        if (zero_count > 0) {
            negative.push(0);
        }
        else
            negative.push(1);
    }
    
    
    while (!positive.empty()) {
        int temp1, temp2;
        temp1 = positive.top();
        positive.pop();
        temp2 = positive.top();
        positive.pop();
        
        sum += temp1 * temp2;
    }
    
    while (!negative.empty()) {
        int temp1, temp2;
        temp1 = negative.top();
        negative.pop();
        temp2 = negative.top();
        negative.pop();
        
        sum += temp1 * temp2;
    }
    
    sum += one_count;
    
    cout << sum;
    return 0;
}
