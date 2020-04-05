#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
	int T, a, b;

	vector<pair<int, int>> cote1;
	vector<pair<int, int>> cote2;

	cote1.push_back({ 500,1 });
	cote1.push_back({ 300,2 });
	cote1.push_back({ 200,3 });
	cote1.push_back({ 50,4 });
	cote1.push_back({ 30,5 });
	cote1.push_back({ 10,6 });

	cote2.push_back({ 512,1 });
	cote2.push_back({ 256,2 });
	cote2.push_back({ 128,4 });
	cote2.push_back({ 64,8 });
	cote2.push_back({ 32,16 });

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int sum1 = 0, sum2 = 0;
		int result1 = 0, result2 = 0;
		scanf("%d %d", &a, &b);

		// case #1. cote1
		if (a != 0) {
			for (int i = 0; i < 6; i++) {
				sum1 += cote1[i].second;
				if (sum1 >= a) {
					result1 = cote1[i].first;
					break;
				}
			}
		}

		// case #2. cote2
		if (b != 0) {
			for (int i = 0; i < 5; i++) {
				sum2 += cote2[i].second;
				if (sum2 >= b) {
					result2 = cote2[i].first;
					break;
				}
			}
		}

		printf("%d\n",(result1 + result2)*10000);

	}

}