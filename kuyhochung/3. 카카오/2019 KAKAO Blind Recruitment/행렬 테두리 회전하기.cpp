#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix;

int rotate (int x1, int y1, int x2, int y2) {
    int min_val = 98765432;
    queue<int> numbers;
    
    x1--; x2--; y1--; y2--;
    
    //enqueue
    for (int i = y1; i <= y2; i++) {
        numbers.push(matrix[x1][i]);
        min_val = min(min_val, matrix[x1][i]);
    }
    for (int i = x1+1; i < x2; i++) {
        numbers.push(matrix[i][y2]);
        min_val = min(min_val, matrix[i][y2]);
    }
    for (int i = y2; i >= y1; i--) {
        numbers.push(matrix[x2][i]);
        min_val = min(min_val, matrix[x2][i]);
    }
    for (int i = x2-1; i > x1; i--) {
        numbers.push(matrix[i][y1]);
        min_val = min(min_val, matrix[i][y1]);
    }
    
    //dequeue
    for (int i = y1+1; i < y2; i++) {
        matrix[x1][i] = numbers.front();
        numbers.pop();
    }
    for (int i = x1; i <= x2; i++) {
        matrix[i][y2] = numbers.front();
        numbers.pop();
    }
    for (int i = y2-1; i > y1; i--) {
        matrix[x2][i] = numbers.front();
        numbers.pop();
    }
    for (int i = x2; i >= x1; i--) {
        matrix[i][y1] = numbers.front();
        numbers.pop();
    }
    
    if (numbers.empty()) return min_val;
    else return -1;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int a = 1;
    for (int i = 0; i < rows; i++) {
        vector<int> buffer;
        for (int j = 0; j < columns; j++) {
            buffer.push_back(a);
            a++;
        }
        matrix.push_back(buffer);
    }
    
    for (int i = 0; i < queries.size(); i++) {
        //answer.push_back(rotate(1,1,100,97));
        answer.push_back(rotate(queries[i][0], queries[i][1], queries[i][2], queries[i][3]));
    }
    
    return answer;
}