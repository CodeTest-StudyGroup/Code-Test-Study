#include <iostream>
#include <algorithm>
using namespace std;

bool w[100][100];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        w[a - 1][b - 1] = 1;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (w[i][k] && w[k][j]) {
                    w[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (!w[i][j] && !w[j][i]) {
                cnt++;
            }
        }
        cout << cnt - 1 << '\n';
    }
}