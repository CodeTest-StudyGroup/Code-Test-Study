#include <iostream>
using namespace std;

#define MAX_D 31

int fibonacci[MAX_D];

int main() {
    
    int D, K;
    cin >> D >> K;
    
    fibonacci[1] = 1;
    fibonacci[2] = 1;
    
    for (int i = 3; i <= D; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    
    //teok D = K = fibonacci[D-2]*teok[1] + fibonacci[D-1]*teok[2]
    
    int teok_f, teok_s;
    for (int i = 1;; i++) {
        teok_f = i;
        int temp = (K-fibonacci[D-2]*teok_f);
        if ((temp % fibonacci[D-1]) != 0) {
            continue;
        }
        teok_s = temp / fibonacci[D-1];
        break;
    }
    
    cout << teok_f << '\n' << teok_s;
    
    return 0;
}
