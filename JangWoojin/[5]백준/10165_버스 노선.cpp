#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct Bus {
    int s, e, idx;
    bool operator<(const Bus& t) const {
        if (s == t.s) return e > t.e;
        return s < t.s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Bus> v;
    int max_e = 0;
    for (int i = 1; i <= m; ++i) {
        int s, e;
        cin >> s >> e;
        if (s > e) {
            max_e = max(max_e, e);
            e += n;
        }
        v.push_back({s, e, i});
    }

    sort(v.begin(), v.end());

    deque<Bus> dq;
    for (auto& bus : v)
        if (dq.empty() || dq.back().e < bus.e) dq.push_back(bus);
    while (!dq.empty() && dq.front().e <= max_e) dq.pop_front();

    sort(dq.begin(), dq.end(),
         [](const Bus& a, const Bus& b) { return a.idx < b.idx; });

    for (auto& bus : dq) cout << bus.idx << ' ';
    cout << endl;

    return 0;
}