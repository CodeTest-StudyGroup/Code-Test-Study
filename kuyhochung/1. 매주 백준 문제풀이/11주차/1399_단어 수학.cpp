#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int N; //단어의 개수, 1 <= N <= 10
vector<pair<int, string> > word;
string word_input;
int answer = 0;
int alphabet_value[26] = {0, };

bool cmp (int a, int b) {
    if (a > b)
        return true;
    else
        return false;
}

int main() {
    
    memset(alphabet_value, 0, sizeof(alphabet_value));
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word_input;
        word.push_back(make_pair(word_input.length(),word_input));
    }
    sort(word.begin(),word.end(),greater<>());
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < word[i].first; j++) {
            alphabet_value[word[i].second[j]-65] += pow(10,word[i].first-(j+1));
        }
    }
    
    sort(alphabet_value, alphabet_value+26, cmp);
    int weight = 9;
    for (int i = 0; i < 26; i++) {
        if (alphabet_value[i] == 0) break;
        answer += alphabet_value[i] * weight;
        weight--;
    }
    
    cout << answer;
    
    return 0;
}