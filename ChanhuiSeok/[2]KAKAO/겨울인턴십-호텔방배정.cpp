#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <hash_map>

using namespace std;

int main() {

	long long k;
	long long bit = 0;
	vector<long long> room_number;
	vector<long long> answer;
	long long Idx;
	hash_map<long long, long long> room;

	k = 10;
	room_number.push_back(1);
	room_number.push_back(3);
	room_number.push_back(4);
	room_number.push_back(1);
	room_number.push_back(3);
	room_number.push_back(1);

	/* 비트마스킹 풀이법 -> 숫자가 크면 시간초과... */
	/*
	for (int i = 0; i < room_number.size(); i++) {
		Idx = room_number[i];

		// 방문하지 않았으면
		if ((bit & (1 << Idx)) == 0) {
			result.push_back(room_number[i]);
			bit = bit | (1 << Idx); // 방문 표시
		}

		// 방문했으면, 이것보다 숫자가 크면서 가장 작은 방의 번호를 넣는다.
		else {
			while (1) {
				if ((bit & (1 << Idx)) == 0) { // 방문하지 않았으면
					result.push_back(Idx);
					bit = bit | (1 << Idx); // 방문 표시
					break;
				}
				else
					Idx++;
			}
		}
	}
	*/

	for (int i = 0; i < room_number.size(); i++) {
		Idx = room_number[i];
		if (room.find(Idx) == room.end()) {
			room.insert({ Idx, 1 });
			answer.push_back(Idx);
		}
		else {
			while (1) {
				Idx += 1;
				if (room.find(Idx) == room.end()) {
					room.insert({ Idx, 1 });
					answer.push_back(Idx);
					break;
				}
			}
		}
	}
	
}