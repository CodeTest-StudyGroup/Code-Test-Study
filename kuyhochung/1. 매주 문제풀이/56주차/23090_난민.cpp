#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

int n;
long long x_abs_sum = 0;
priority_queue<int, vector<int>, greater<int> > higher_y;
priority_queue<int> lower_y;

long long prev_dist = -1;
int prev_mid = -1;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int input_x, input_y;
        cin >> input_x >> input_y;
        
        int s1 = (int)lower_y.size(), s2 = (int)higher_y.size();
        
        //y좌표들의 중앙값 구하기
        if (higher_y.size() == lower_y.size()) lower_y.push(input_y);
        else if (higher_y.size() + 1 == lower_y.size()) higher_y.push(input_y);
        if (!lower_y.empty() && !higher_y.empty()) {
            if (higher_y.top() < lower_y.top()) {
                int htemp, ltemp;
                htemp = higher_y.top();
                ltemp = lower_y.top();
                higher_y.pop(); lower_y.pop();
                higher_y.push(ltemp); lower_y.push(htemp);
            }
        }
        int mid_val = lower_y.top();
        long long dist_sum;
        
        if (prev_dist == -1 && prev_mid == -1) {
            dist_sum = abs(input_x);
        }
        else {
            dist_sum = prev_dist + abs(prev_mid - mid_val) * abs(s1-s2) + abs(mid_val - input_y) + abs(input_x);
        }

        //출력 및 현재까지의 값 저장
        cout << mid_val << " " << dist_sum << '\n';
        prev_mid = mid_val;
        prev_dist = dist_sum;
    }
    return 0;
}
