#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001
#define INF 1000000001

int N, M;
long long numbers[MAX_N];
vector < pair < long long, long long> > tree(MAX_N * 4);

pair<long long, long long> init (int start, int end, int node) {
    if (start == end) {
        tree[node].first = numbers[start];
        tree[node].second = numbers[start];
        return tree[node];
    }
    else {
        pair<long long, long long> left = init(start, (start+end)/2, node*2);
        pair<long long, long long> right = init((start+end)/2 + 1, end, node*2 + 1);
        tree[node].first = min(left.first, right.first);
        tree[node].second = max(left.second, right.second);
        return tree[node];
    }
}

pair<long long, long long> find(int left, int right, int node, int start, int end) {
    if (start > right || end < left)
        return make_pair(INF, 0);
    if (left <= start && right >= end)
        return tree[node];
    
    pair<long long, long long> temp_left = find(left, right, node*2, start, (start+end)/2);
    pair<long long, long long> temp_right = find(left, right, node*2+1, (start+end)/2+1, end);
    pair<long long, long long> result;
    result.first = min(temp_left.first, temp_right.first);
    result.second = max(temp_left.second, temp_right.second);
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }
    
    init(1, N, 1);
    
    for (int i = 0; i < M; i++) {
        int left, right;
        cin >> left >> right;
        pair <long long, long long> temp = find(left, right, 1, 1, N);
        cout << temp.first << " " << temp.second << '\n';
    }
    
    return 0;
}
