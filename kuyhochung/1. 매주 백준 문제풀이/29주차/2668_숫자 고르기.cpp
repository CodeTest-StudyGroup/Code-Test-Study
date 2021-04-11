#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 101

int numbers[MAX_N];
int n;
int result = 0;
vector<int> numberList;
bool globalVisited[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
    }
    for (int j = 1; j <= n; j++) {
        globalVisited[j] = false;
    }

    //각 숫자를 시작점으로 두고 비교한다.
    for (int i = 1; i <= n; i++) {
        int first = i;
        int second = numbers[i];
        vector<int> firstList;
        vector<int> secondList;
        //방문 배열 선언 및 초기화
        //첫째 줄, 둘째 줄의 숫자를 의미. 맨 처음에는 시작점으로 초기화한다.
        bool visited[MAX_N];
        for (int j = 1; j <= n; j++) {
            visited[j] = false;
            visited[j] = false;
        }
        while(1) {
            if (visited[first] == true && visited[first] == true) break;
            firstList.push_back(first);
            secondList.push_back(second);
            visited[first] = true;
            first = second;
            second = numbers[second];
        }
        
        sort(firstList.begin(), firstList.end());
        sort(secondList.begin(), secondList.end());
        bool trigger = true;
        for (int k = 0; k < firstList.size(); k++) {
            if (firstList[k] != secondList[k]) trigger = false;
        }
        if (trigger == true) {
            for (int k = 0; k < firstList.size(); k++) {
                int now = firstList[k];
                if (globalVisited[now] == false) {
                    globalVisited[now] = true;
                    numberList.push_back(firstList[k]);
                }
            }
        }
    }
    
    result = (int)numberList.size();
    sort(numberList.begin(), numberList.end());
    cout << result << '\n';
    for (int i = 0; i < numberList.size(); i++) {
        cout << numberList[i] << '\n';
    }
    return 0;
}
