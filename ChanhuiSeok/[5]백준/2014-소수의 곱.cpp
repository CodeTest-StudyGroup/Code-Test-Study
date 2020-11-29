#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>

using namespace std;

long long K, N;
vector<long long> prime;
set<long long> dic;
priority_queue<long long, vector<long long>, greater<>> pq;

int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		long long tmp; cin >> tmp;
		prime.push_back(tmp);
		dic.insert(tmp);
		pq.push(tmp);
	}

	int idx = 0;
	long long cur = 0;
	long long maxv = prime[K - 1];
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		idx++;

		if (idx == N) break;

		for (int k = 0; k < prime.size(); k++) {
			if (pq.size() > N && cur * prime[k] > maxv) break;
			long long target = cur * prime[k];
			if (dic.count(target) == 0) {
				pq.push(target);
				dic.insert(target);
				maxv = max(maxv, cur * prime[k]);
			}
		}
	}

	cout << cur;
	return 0;
}