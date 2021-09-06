#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int testCase;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testCase;
    
    while(testCase--) {
        string command;
        int n;
        string number_array;
        cin >> command >> n >> number_array;
        
        if (number_array[0] == '[' && number_array.back() == ']') {
            number_array = number_array.substr(1);
            number_array.pop_back();
        }
        
        istringstream ss(number_array);
        vector<int> number;
        string buffer;
        number.clear();
        while(getline(ss, buffer, ',')) {
            number.push_back(stoi(buffer));
        }
        
        bool reversed = false;
        int forward = 0, backward = 0;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'R') {
                reversed = !reversed;
            }
            else if (command[i] == 'D') {
                if (!reversed) forward++; else backward++;
            }
            else {
                return -1;
            }
        }
        bool calc_error = false;
        if (forward + backward > n) calc_error = true;
        if (!calc_error) {
            vector<int> next;
            next.assign(number.begin() + forward, number.end() - backward);
            cout << '[';
            if (!next.empty()) {
                if (!reversed) {
                    for (int i = 0; i < next.size() - 1; i++) {
                        cout << next[i] << ",";
                    }
                    cout << next.back();
                }
                else {
                    for (int i = (int)next.size() - 1; i > 0; i--) {
                        cout << next[i] << ",";
                    }
                    cout << next[0];
                }
            }
            cout << "]\n";
        }
        else {
            cout << "error\n";
        }
    }
    return 0;
}
