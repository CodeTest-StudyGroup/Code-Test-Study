//
//  main.cpp
//  211130-01
//
//  Created by 박경선 on 2021/11/30.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long solution(vector<vector<int>> land, int P, int Q) {
    long long answer = LLONG_MAX;
    vector<long long> flat;
    long long total = 0;
    long long prev = -1, block = 0;
    
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            flat.push_back(land[i][j]);
            total+= land[i][j];
        }
    }
    
    sort(flat.begin(), flat.end());

    for (int cur = 0; cur < flat.size(); cur++) {
        if (prev != flat[cur]) {
            long long add = flat[cur] * cur - block;
            long long remove = total - (flat.size() * flat[cur]) + add;
            long long cost = add * P + remove * Q;
            
            if (answer > cost) answer = cost;
            prev = flat[cur];
        }
        block += flat[cur];
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    long long result = solution({{4, 4, 3}, {3, 2, 2}, { 2, 1, 0}}, 5, 3);
    cout << "result : " << result;
    return 0;
}
