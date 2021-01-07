#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 26

int main() {
	int N, total = 0, num = 9;
	string str;
    // 알파벳 별 개수를 저장할 배열
	int alphabet[MAX] = {0};
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp = 1;
		cin >> str;
        // 문자열의 각 원소의 자릿수를 배열에 더하여 저장 
        // 'AB'일 경우 A - 10, B - 1 
		for (int j = str.length() - 1; j >= 0; j--) {
			alphabet[str[j]-'A'] += temp;
			temp *= 10;
		}
	}
    // 알파벳 개수를 기준으로 내림차순으로 정렬
	sort(alphabet, alphabet + MAX, greater<int>());
    // 가장 많이 등장하는 알파벳부터 큰 수를 할당하여 총합을 구함
	for (int i = 0; i < MAX; i++) {
		total += alphabet[i] * num--;
	}

	cout << total;
}