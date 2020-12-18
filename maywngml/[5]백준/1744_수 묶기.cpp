#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int N, num, answer = 0;
    // 양수 벡터와 음수 벡터의 크기를 저장할 변수
	int positiveSize, negativeSize;
    // 양수들을 저장할 벡터
	vector<int> positive;
    // 음수들을 저장할 벡터
	vector<int> negative;
    // 1들을 저장할 벡터
	vector<int> one;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
        // 입력값을 조건에 맞는 벡터에 저장
		if (num == 1)
			one.push_back(num);
		else if (num > 0)
			positive.push_back(num);
		else
			negative.push_back(num);
	}
    // 양수는 내림차순으로 정렬
	sort(positive.begin(), positive.end(), greater<int>());
    // 음수는 오름차순으로 정렬 
    // (음수끼리 곱할시에는 양수로 변환되므로 숫자가 작은걸 곱할수록 그 값이 더 커짐)
	sort(negative.begin(), negative.end());
    // 벡터의 크기들을 변수에 대입
	positiveSize = positive.size();
	negativeSize = negative.size();

	for (int i = 0; i < positiveSize; i++) {
        // 마지막 원소일때는 해당 원소 더함
		if (i == positiveSize - 1)
			answer += positive[i];
        // 마지막 원소가 아닐시에는 현재 원소와 다음 원소를 곱하여 더하고 i를 1 증가시킴
		else {
			answer += positive[i] * positive[i + 1];
			i++;
		}
	}

	for (int i = 0; i < negativeSize; i++) {
        // 마지막 원소일때는 해당 원소 더함
		if (i == negativeSize - 1)
			answer += negative[i];
        // 마지막 원소가 아닐시에는 현재 원소와 다음 원소를 곱하여 더하고 i를 1 증가시킴
		else {
			answer += negative[i] * negative[i + 1];
			i++;
		}
	}
    // one벡터의 크기를 더함
	answer += one.size();

	cout << answer;
}