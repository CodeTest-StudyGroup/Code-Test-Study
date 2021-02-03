#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int H, W, minNum, answer = 0;

    cin >> H >> W;
    vector<int> block(W);

    for (int i = 0; i < W; i++)
    {
        cin >> block[i];
    }

    for (int i = 1; i < W - 1; i++)
    {
        // 현재 원소를 기준으로 왼쪽 배열의 최대값을 저장
        int leftMax = *max_element(block.begin(), block.begin() + i);
        // 현재 원소를 기준으로 오른쪽 배열의 최대값을 저장
        int rightMax = *max_element(block.begin() + i + 1, block.end());
        // 두 최대값 중 작은 값을 저장
        minNum = min(leftMax, rightMax);
        // 현재 블록 원소가 minNum보다 작을 경우
        if (block[i] < minNum)
            // minNum에서 현재 원소를 뺀 값(빗물이 고이는 칸만큼)을 answer에 더함
            answer += minNum - block[i];
    }

    cout << answer << '\n';
}