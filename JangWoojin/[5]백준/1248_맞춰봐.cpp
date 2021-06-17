#include <iostream>

using namespace std;

const int MAX = 10;

struct Type {
    char type;

    Type() {}

    Type(char type) : type(type) {}

    bool operator==(const Type& rhs) const {
        return type == rhs.type;
    }

    bool valid(int x) {
        if (type == '-') {
            return x < 0;
        } else if (type == '+') {
            return x > 0;
        }
        return x == 0;
    }
} types[MAX][MAX];

int num[MAX];
int n;

bool valid(int idx) {
    int sum = 0;
    for (int i = idx; i >= 0; i--) {
        sum += num[i];
        if (!types[i][idx].valid(sum))
            return false;
    }
    return true;
}

void back_tracking(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++)
            cout << num[i] << ' ';
        cout << endl;
        exit(0);
    }

    for (int x = -MAX; x <= MAX; x++) {
        num[idx] = x;
        if (valid(idx)) back_tracking(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            char ch;
            cin >> ch;
            types[i][j] = Type(ch);
        }
    }

    back_tracking(0);

    return 0;
}
