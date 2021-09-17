#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_correct_string(string input) {
    stack<char> buffer;
    for (int i = 0; i < input.size(); i++) {
        if ((input[i] == '(') || (input[i] == '{') || (input[i] == '['))
            buffer.push(input[i]);
        else {
            while(1) {
                if (buffer.empty()) return false;
                char temp = buffer.top();
                buffer.pop();
                if (input[i] == ')') {
                    if (temp == '(') break;
                }
                if (input[i] == '}') {
                    if (temp == '{') break;
                }
                if (input[i] == ']') {
                    if (temp == '[') break;
                }
            }
        }
    }
    if (buffer.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    
    if (s == "") return 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (is_correct_string(s)) answer++;
        string temp = "";
        temp = s.substr(1);
        temp += s[0];
        s = temp;
    }
    
    return answer;
}