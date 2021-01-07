#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, ans = 0, i, j;
  cin >> n;
  cin >> i >> j;
  for (int k = 0; k < n - 1; k++) {
    int x, y;
    cin >> x >> y;
    if (x > j) {
      ans += j - i;
      i = x;
      j = y;
    } else {
      j = max(j, y);
    }
  }

  cout << ans + j - i << endl;

  return 0;
}
