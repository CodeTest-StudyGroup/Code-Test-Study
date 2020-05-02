#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> maps;
int solution(vector<vector<string>> clothes) {
    int result, temps;
    map<string, int>::iterator iterA;
    for (int i = 0; i < clothes.size(); i++) 
        maps[clothes[i][1]] += 1;
    
    result = 1;
    for (iterA = maps.begin(); iterA != maps.end(); iterA++) {
        temps = (1 + iterA->second);
        result *= temps;
    }
    return result - 1;
}