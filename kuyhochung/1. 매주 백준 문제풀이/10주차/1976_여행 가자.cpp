#include <iostream>
using namespace std;
#define MAX_N 201
int N, M;
int parent[MAX_N];
int first_parent, input;

int find_parent (int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = find_parent(parent[a]);
}

void make_pair(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    parent[a] = b;
}

int main() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> input;
            if (input == 1)
                make_pair(i, j);
        }
    }

    cin >> input;
    first_parent = find_parent(input);
    for (int i = 1; i < M; i++) {
        cin >> input;
        if (first_parent != find_parent(input)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
