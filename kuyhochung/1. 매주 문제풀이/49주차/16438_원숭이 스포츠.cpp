#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int print_count = 0;
char answer[8][101];

void combination (int start, int end, int depth) {
    if (start >= end || depth == 7) return;
    print_count = max(print_count, depth);
    
    int mid = (start + end) / 2;
    
    for (int i = start; i <= end; i++) {
        if (i <= mid) answer[depth][i] = 'A';
        else answer[depth][i] = 'B';
    }
    
    combination(start, mid, depth+1);
    combination(mid+1, end, depth+1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    combination(1, n, 0);

    for (int i = 0; i <= print_count; i++) {
        for (int j = 1; j <= n; j++) {
            if (answer[i][j] == '\0') {
                if (j % 2 == 1) answer[i][j] = 'A';
                else answer[i][j] = 'B';
            }
            cout << answer[i][j];
        }
        cout << '\n';
    }
    
    int b_loc = 0;
    while(print_count != 6) {
        for (int i = 0; i < n; i++) {
            if (i == b_loc) cout << 'B'; else cout << 'A';
        }
        cout << '\n';
        b_loc = (b_loc+1) % n; print_count++;
    }
    
    return 0;
}
