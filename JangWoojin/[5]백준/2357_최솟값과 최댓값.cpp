#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

struct RMQ {
    int n;
    vector<int> rangeMin;

    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 1, 0, n - 1);
    }

    int init(const vector<int>& array, int node, int left, int right) {
        if (left == right) return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        return rangeMin[node] = min(init(array, node * 2, left, mid),
                                    init(array, node * 2 + 1, mid + 1, right));
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) return INF;
        if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
                   query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    int query(int left, int right) { return query(left, right, 1, 0, n - 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = -arr[i];
    }

    RMQ rangeMinQuery(arr);
    RMQ rangeMaxQuery(arr2);

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        cout << rangeMinQuery.query(a - 1, b - 1) << ' ';
        cout << -rangeMaxQuery.query(a - 1, b - 1) << '\n';
    }

    return 0;
}