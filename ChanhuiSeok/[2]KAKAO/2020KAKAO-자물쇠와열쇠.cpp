#include <string>
#include <vector>

using namespace std;

int arr[100][100];

// 시계 방향으로 회전
vector<vector<int>> clockwise(vector<vector<int>> arr) {
    int rowSize = arr.size();
    vector<vector<int>> copies;
    vector<int> temp;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = arr.size() - 1; j >= 0; j--) {
            temp.push_back(arr[j][i]);
        }
        copies.push_back(temp);
        temp.clear();
    }
    return copies;
}

// 가운데 배치된 lock이 모두 1이 될 때만 답이 될 수 있다
bool isAllOne(int startRow, int startCol, int lockSize) {
    for (int i = startRow; i < startRow + lockSize; i++) {
        for (int j = startCol; j < startCol + lockSize; j++) {
            if (arr[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool isPossible(vector<vector<int>> lock, vector<vector<int>> key, int keySize, int lockSize) {

    int lock_startRow = lockSize - 1;
    int lock_startCol = lockSize - 1;

    // 정가운데에 lock 을 배치해 놓는다.
    for (int i = lock_startRow; i < lock_startRow + lockSize; i++) {
        for (int j = lock_startCol; j < lock_startCol + lockSize; j++) {
            arr[i][j] = lock[i - lock_startRow][j - lock_startCol];
        }
    }

    // 하나하나 살펴본다.
    for (int i = 0; i < lockSize * 2; i++) {
        for (int j = 0; j < lockSize * 2; j++) {

            for (int k = 0; k < key.size(); k++) {
                for (int m = 0; m < key.size(); m++) {
                    arr[i + k][j + m] += key[k][m];
                }
            }

            // lock이 모두 1일 경우
            if (isAllOne(lock_startRow, lock_startCol, lockSize)) {
                return true;
            }

            for (int k = 0; k < key.size(); k++) {
                for (int m = 0; m < key.size(); m++) {
                    arr[i + k][j + m] -= key[k][m];
                }
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer;

    for (int i = 0; i < 4; i++) {
        answer = isPossible(lock, key, key.size(), lock.size());
        if (answer) {
            return true;
        }

        key = clockwise(key);
    }

    return false;
}