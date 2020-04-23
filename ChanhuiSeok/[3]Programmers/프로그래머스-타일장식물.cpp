#include <string>
#include <vector>

using namespace std;

long long int arr[81];
long long int dp[81];

long long solution(int N) {

	arr[1] = 1; arr[2] = 1;
	dp[1] = 4;

	for (int i = 3; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i] * 2;
	}

	return dp[N];
}