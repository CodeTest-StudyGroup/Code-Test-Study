#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int charExist[26] = {0, };
int answer = 0;
int inputLength = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    string input;
    cin >> input;
    inputLength = (int)input.size();
    
    //각 문자별 등장 빈도를 센다.
    for (int i = 0; i < input.size(); i++) {
        int current = (int)(input[i] - 'A');
        charExist[current]++;
    }
    
    //비교할 문자들 입력
    for (int i = 1; i < n; i++) {
        string nextInput;
        cin >> nextInput;
        int nextInputLength = (int)nextInput.size();
        
        int compareExist[26];
        for (int i = 0; i < 26; i++) {
            compareExist[i] = charExist[i];
        }
        
        for (int i = 0; i < nextInput.size(); i++) {
            int current = (int)(nextInput[i] - 'A');
            compareExist[current]--;
        }
        
        bool equivalent = true;
        for (int i = 0; i < 26; i++) {
            if (compareExist[i] != 0) equivalent = false;
        }
        
        
        //둘이 같은 경우
        if (inputLength == nextInputLength && equivalent) {
            answer++;
        }
        //변경하는 경우
        else if (inputLength == nextInputLength) {
            bool available = false;
            bool available2 = true;
            int minusOne = 0, plusOne = 0;
            for (int i = 0; i < 26; i++) {
                if (compareExist[i] == -1) minusOne++;
                else if (compareExist[i] == 1) plusOne++;
                else if (compareExist[i] != 0) available2 = false;
            }
            if (minusOne == 1 && plusOne == 1) available = true;
            if (available && available2) {
                answer++;
            }
        }
        //추가하는 경우
        else if (inputLength + 1 == nextInputLength) {
            bool available = false;
            int minusOne = 0;
            for (int i = 0; i < 26; i++) {
                if (compareExist[i] == -1) minusOne++;
            }
            if (minusOne == 1) available = true;
            if (available) {
                answer++;
            }
        }
        //제거하는 경우
        else if (inputLength == nextInputLength + 1) {
            bool available = false;
            int plusOne = 0;
            for (int i = 0; i < 26; i++) {
                if (compareExist[i] == 1) plusOne++;
            }
            if (plusOne == 1) available = true;
            if (available) {
                answer++;
            }
        }
    }

    
    cout << answer;
     
    return 0;
}