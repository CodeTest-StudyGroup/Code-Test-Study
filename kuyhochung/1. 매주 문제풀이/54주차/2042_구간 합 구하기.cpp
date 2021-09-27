#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, k;
vector<long long> arr;

int closest_square (vector<long long> &arr) {
    int a = (int)arr.size();
    int i = 1;
    while(1) {
        if (pow(i, 2) >= a) break;
        i++;
    }
    return pow(i,2) * 4;
}

long long segment_tree(vector<long long> &tree, int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = segment_tree(tree, start, mid, node*2) + segment_tree(tree, mid+1, end, node*2+1);
}

long long get_sum (vector<long long> &tree, int start, int end, int left, int right, int node) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return get_sum(tree, start, mid, left, right, node*2) + get_sum(tree, mid+1, end, left, right, node*2+1);
}

void edit_value(vector<long long> &tree, int start, int end, int node, int index, long long value) {
    if (index < start || index > end) return;
    tree[node] += value;
    if (start == end) return;
    int mid = (start + end) / 2;
    edit_value(tree, start, mid, node*2, index, value);
    edit_value(tree, mid+1, end, node*2+1, index, value);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    arr.push_back(-1);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int square = closest_square(arr);
    vector<long long> tree(square);
    segment_tree(tree, 1, n, 1);
    
    for (int i = 0; i < m+k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            //값 변경
            long long difference = c - arr[b];
            arr[b] = c;
            edit_value(tree, 1, n, 1, b, difference);
        }
        else if (a == 2) {
            //구간 b, c의 합 출력
            cout << get_sum(tree, 1, n, b, c, 1) << '\n';
        }
    }
    return 0;
}