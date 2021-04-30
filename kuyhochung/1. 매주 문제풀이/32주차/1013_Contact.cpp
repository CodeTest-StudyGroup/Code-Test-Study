#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++){
        string signal;
        cin >> signal;
        if (regex_match (signal, regex("(100+1+|01)+")))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
