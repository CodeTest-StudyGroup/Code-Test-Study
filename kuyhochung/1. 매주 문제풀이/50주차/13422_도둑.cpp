#include <iostream>
#include <vector>
using namespace std;

int testcase;

void steal_money() {
    int n, m, k;
    vector<int> houses;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        houses.push_back(temp);
    }
    
    int can_steal = 0, total_money = 0;
    
    //매번 모든 합을 구하면 비효율적이다.
    //loop 형태이므로, 한 칸씩 전진하며 맨 뒤의 값을 빼고 맨 앞에는 새 값을 추가해 주면 된다.
    
    for (int i = 0; i < m; i++) {
        total_money += houses[i];
    }
    if (total_money < k) can_steal++;
    
    //n == m인 경우에 대한 예외 처리
    if (n != m) {
        for (int i = 0; i < n-1; i++) {
            total_money -= houses[i];
            int next_house = i + m; if (next_house >= n) next_house -= n;
            total_money += houses[next_house];
            if (total_money < k) can_steal++;
        }
    }
    
    //경우의 수를 출력
    cout << can_steal << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    
    while(testcase--) {
        steal_money();
    }
    
    return 0;
}
