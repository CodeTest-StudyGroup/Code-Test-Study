#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string input;
vector <pair <int, char> > buffer;
bool visited[100];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
    
    for (int i = 0; i < input.size(); i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < input.size(); i++) {
        string temp = "";
        int tempPosition = -1;
        
        for (int j = 0; j < input.size(); j++) {
            if (visited[j]) continue;
            vector <pair <int, char> > copyBuffer;
            copyBuffer.resize((int)(buffer.size()));
            string tempTemp;
            copy(buffer.begin(), buffer.end(), copyBuffer.begin());
            copyBuffer.push_back({j, input[j]});
            sort(copyBuffer.begin(), copyBuffer.end());
            for (int k = 0; k < copyBuffer.size(); k++) {
                tempTemp += copyBuffer[k].second;
            }
            if (copyBuffer.size() > temp.size()) {
                temp = tempTemp;
                tempPosition = j;
            }
            else if (temp.compare(tempTemp) > 0) {
                temp = tempTemp;
                tempPosition = j;
            }
        }
        buffer.push_back({tempPosition, input[tempPosition]});
        sort(buffer.begin(), buffer.end());
        visited[tempPosition] = true;
        for (int j = 0; j < buffer.size(); j++) {
            cout << buffer[j].second;
        }
        cout << endl;
    }
    return 0;
}
