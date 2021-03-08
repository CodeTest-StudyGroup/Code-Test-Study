#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N 10001

int countByRange(vector<string> &v, string leftValue, string rightValue) {
    vector<string>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<string>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    
    return rightIndex - leftIndex;
}

string replaceAll(string str, string from, string to) {
    string result = str;
    int pos = 0;
    
    while ((pos = result.find(from, pos)) != string::npos) {
        result.replace(pos, from.size(), to);
        pos += to.size();
    }
    
    return result;
}

vector<string> arr[MAX_N];
vector<string> reversed_arr[MAX_N];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        arr[word.size()].push_back(word);
        reverse(word.begin(), word.end());
        reversed_arr[word.size()].push_back(word);
    }
    
    for (int i = 0; i < MAX_N; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(reversed_arr[i].begin(), reversed_arr[i].end());
    }
    
    for (int i = 0; i < queries.size(); i++) {
        string q = queries[i];
        int result = 0;
        if (q[0] != '?')
            result = countByRange(arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        else {
            reverse(q.begin(), q.end());
            result = countByRange(reversed_arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
        answer.push_back(result);
    }
    return answer;
}
