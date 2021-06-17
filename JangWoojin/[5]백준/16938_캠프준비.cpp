#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 15;
int a[MAX];
vector<int> cand;
int n, l, r, x;
int answer;

void back_tracking(int idx, int cnt, int sum) {
    if (sum > r) return;

    if (cand.size() == cnt) {
        if (l <= sum && cand.back() - cand.front() >= x)
            answer++;
        return;
    }

    for (int i = idx; i < n; i++) {
        cand.push_back(a[i]);
        back_tracking(i + 1, cnt, sum + a[i]);
        cand.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for (int i = 2; i <= n; i++) {
        back_tracking(0, i, 0);
    }

    cout << answer << endl;

    return 0;
}
