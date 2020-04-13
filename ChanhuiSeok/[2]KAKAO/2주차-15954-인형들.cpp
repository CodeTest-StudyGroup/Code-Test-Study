#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	vector <double> v;
	int N, K;
	int tempK;
	int idx = 0;
	double input;
	double sum = 0, m = 0;
	double var = 0, sd = 0;
	double minSd = 9999999999999;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%lf", &input);
		v.push_back(input);
	}

	tempK = K;

	while (tempK <= N) {

		if (idx + tempK - 1 <= N - 1) {

			for (int j = idx; j < idx + tempK; j++) {
				sum += v[j];
			}
			// 평균
			m = sum / (double)tempK;
			// 표준편차
			for (int j = idx; j < idx + tempK; j++) {
				var = var + (v[j] - m) * (v[j] - m);
			}
			var = var / (double)tempK;
			sd = sqrt(var);

			if (minSd > sd)
				minSd = sd;

			sum = 0; var = 0;
			idx += 1;
		}
		else {
			idx = 0;
			tempK += 1;
		}
	}

	printf("%.11lf", minSd);

}