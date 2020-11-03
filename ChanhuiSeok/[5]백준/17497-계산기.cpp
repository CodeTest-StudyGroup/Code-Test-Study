#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <bitset>
#include <map>

using namespace std;

#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3

string oper[4] = { "[+]","[-]","[*]","[/]" };
// 덧셈, 뺄셈, 곱셈, 나눗셈

long long N;
// N에서 시작해서 0이 될 때까지 해 보기

vector<string> answer;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // N을 이루는 모든 1들을 0으로 바꾸는 것이 목표
    // 그런데 연산이 *2, /2, +2, -2 같은 것밖에 없으므로
    // 첫번째 비트와 두번째 비트 가지고만 놀아야 함
    while (N) {
        if (N & 1) { // N이 홀수일 경우, 마지막에 나눗셈 한 번으로 구해지도록
            answer.push_back(oper[DIV]);
            N *= 2; // 두배 해 놓아야, / 연산으로 목표에 도달 가능
        }
        else if (N & (1LL << 1)) { // 1번 비트(두번째 비트)는 2를 만드는 숫자
            answer.push_back(oper[PLUS]);
            N -= 2;
        }
        else {
            answer.push_back(oper[MUL]);
            N /= 2;
        }
    }
    if (answer.size() > 99) cout << -1;
    else {
        cout << answer.size() << '\n';
        for (int i = answer.size() - 1; i >= 0; i--) {
            cout << answer[i] << " ";
        }
    }

}
