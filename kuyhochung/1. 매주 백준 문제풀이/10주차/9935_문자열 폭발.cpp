#include <iostream>
#include <string>

using namespace std;
#define MAX_N 1000001

string input;
string explosive;
char ans[MAX_N];
int idx = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> input;
    cin >> explosive;
    
    int inlen = (int)input.length();
    int exlen = (int)explosive.length();
    
    for (int i = 0; i < inlen; i++) {
        ans[idx++] = input[i];
        if (ans[idx-1] == explosive[exlen-1]) {
            if (idx - exlen < 0)
                continue;
            bool isExplosive = true;
            for (int j = 0; j < exlen; j++) {
                if (ans[idx-1-j] != explosive[exlen-1-j]) {
                    isExplosive = false;
                    break;
                }
            }
            if (isExplosive == true)
                idx -= exlen;
        }
    }
    ans[idx] = '\0';
    if (idx == 0)
        cout << "FRULA";
    else
        cout << ans;
    return 0;
}
