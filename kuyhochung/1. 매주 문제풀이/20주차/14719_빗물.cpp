#include <iostream>
using namespace std;

#define MAX_N 500
int H, W;
int rain = 0;
int blocks[MAX_N];

int main() {
    cin >> H >> W;
    
    for (int i = 0; i < W; i++) {
        cin >> blocks[i];
    }
    
    for (int i = 0; i < W; i++) {
        for (int j = H - blocks[i]; j > 0; j--) {
            bool leftCheck = false, rightCheck = false;
            
            for (int l = 0; l < i; l++) {
                if (blocks[l] >= j + blocks[i]) {
                    leftCheck =  true;
                    break;
                }
            }
            for (int r = i+1; r < W; r++) {
                if (blocks[r] >= j + blocks[i]) {
                    rightCheck =  true;
                    break;
                }
            }
            if (leftCheck && rightCheck) {
                rain += j;
                break;
            }
        }
    }
    
    cout << rain;
    return 0;
}
