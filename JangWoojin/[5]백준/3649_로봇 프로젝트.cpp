#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    while (cin >> x) {
        cin >> n;
        x *= 1e7;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int i = 0;
        int j = n - 1;
        while (i < j) {
            int sum = a[i] + a[j];
            if (sum == x)
                break;
            else if (sum < x)
                i++;
            else if (sum > x)
                j--;
        }

        if (i >= j)
            cout << "danger" << endl;
        else
            cout << "yes " << a[i] << ' ' << a[j] << endl;
    }

    return 0;
}
