#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int length = weak.size();
    int dist_size = dist.size();
    int answer = dist_size + 1;             //최대 9의 값을 가진다.
    
    for (int i = 0; i < length; i++)
        weak.push_back(weak[i] + n);
    
    for (int start = 0; start < length; start++) {
        do {
            int num_friend = 1;
            int position = weak[start] + dist[num_friend-1];
            for (int index = start; index < start + length; index++) {
                if (position < weak[index]) {
                        num_friend++;
                    if (num_friend > dist_size)
                        break;
                    position = weak[index] + dist[num_friend - 1];
                }
            }
            answer = min (answer, num_friend);
            
        } while (next_permutation(dist.begin(), dist.end()));
    }
    
    if (answer > dist_size) return -1;
    return answer;
}