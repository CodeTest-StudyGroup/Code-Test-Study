#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string,int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool cmp2(pair<int,int> a, pair<int, int> b) {
    //재생횟수용
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int > lists;
    map<string, vector < pair<int, int> > > songs;
    
    for (int i = 0; i < genres.size(); i++) {
        lists[genres[i]]+= plays[i];
    }
    
    for (int i = 0; i < genres.size(); i++) {
        songs[genres[i]].push_back({plays[i], i});
    }
    
    
    vector<pair <string, int> > lists_v (lists.begin(), lists.end());
    sort(lists_v.begin(), lists_v.end(), cmp);
    
    for (int i = 0; i < lists_v.size(); i++) {
        
        string current_key = lists_v[i].first;
        vector<pair<int, int>> songIDs = songs[current_key];
        //재생수, 음악번호
        sort(songIDs.begin(), songIDs.end(), cmp2);
        if (songIDs.size() == 1) answer.push_back(songIDs[0].second);
        else {
            for (int j = 0; j < 2; j++) {
                answer.push_back(songIDs[j].second);
            }
        }
        
    }
    return answer;
}