#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 500001

int n;
vector<int> numbers;
int arr2[MAX_N];

long long navigate (int start, int end) {
    if (start == end) return 0;
    
    int mid = (start + end) / 2;
    long long answer = navigate(start, mid) + navigate(mid+1, end);
    
    int i = start, j = mid+1;
    int idx = 0;
    while (i <= mid || j <= end) {
        if (i <= mid && ((j > end) || numbers[i] <= numbers[j])) {
            arr2[idx++] = numbers[i++];
        }
        else {
            answer += (mid-i+1)*1LL;
            arr2[idx++] = numbers[j++];
        }
    }
    
    for (int i = start; i <= end; i++) {
        numbers[i] = arr2[i - start];
    }
    return answer;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        numbers.push_back(temp);
    }
    
    long long answer = navigate(0, n-1);
    cout << answer;
    return 0;
}
