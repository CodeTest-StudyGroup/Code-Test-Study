#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    while (cin >> n) {
        vector<int> v(n, 2e9);

        for (int i = 0, x; i < n; i++) {
            cin >> x;
            int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
            v[idx] = x;
        }
        cout << find(v.begin(), v.end(), 2e9) - v.begin() << endl;
    }

    return 0;
}