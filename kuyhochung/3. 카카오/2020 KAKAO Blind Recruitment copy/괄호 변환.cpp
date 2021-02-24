#include <string>
#include <vector>

using namespace std;

bool is_proper(string p) {
    int left_bracket = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            left_bracket++;
        else {
            left_bracket--;
            if (left_bracket < 0)
                return false;
        }
    }
    if (left_bracket == 0)
        return true;
}

int balanced_string_index (string p) {
    int left_bracket = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            left_bracket++;
        else
            left_bracket--;
        if (left_bracket == 0)
            return i;
    }
    return -1;
}

string solution(string p) {
    string answer = "";
    if (p == "") return answer;
    
    string u, v;
    int balanced_index = balanced_string_index(p);
    u = p.substr(0, balanced_index + 1);
    v = p.substr(balanced_index + 1);
    
    if (is_proper(u)) answer =  u + solution(v);
    else {
        answer = "(";
        answer += solution(v) + ")";
        u = u.substr(1, u.size()-2);
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
    }
    
    return answer;
}