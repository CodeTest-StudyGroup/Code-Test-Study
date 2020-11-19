#include <string>
#include <vector>

using namespace std;


int solution(string name) {
    int answer = 0;
    
    for (int i = 0; i < name.length(); i++) {
        if (name[i] <= 78)
            answer += name[i] % 65;
        else
            answer += 91-name[i];
    }
    
    int min_move = name.length() - 1;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] != 'A') {
            int next = i+1;
            while(next < name.length() && name[next] == 'A')
                next++;
            int move = 2*i + name.length() - next;
            min_move = min(min_move, move);
        }
    }
    
    return answer + min_move;
}
