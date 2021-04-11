#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100001

int parent[MAX_N];
vector<int> planes;
int g, p;

int get_parent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = get_parent(parent[x]);
}

void make_union(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g >> p;
    for (int i = 0; i <= g; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < p; i++) {
        int temp;
        cin >> temp;
        planes.push_back(temp);
    }
    int cnt = 0;
    for (int i = 0; i < p; i++) {
        int temp = planes[i];
        int now = get_parent(temp);
        if (now == 0) break;
        make_union(now, now-1);
        cnt++;
    }
    cout << cnt;
    return 0;
}
