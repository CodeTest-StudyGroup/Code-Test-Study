#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

char map[104][105];
bool visited[104][105];
int key[26];
int h, w;
int answer;

bool bfs()
{
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    bool flag = false;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            char &c = map[nx][ny];
            if (c == '*' || visited[nx][ny])
                continue;
            if (c == '$')
                answer++;
            else if ('A' <= c && c <= 'Z' && !key[c - 'A'])
                continue;
            else if ('a' <= c && c <= 'z')
            {
                key[c - 'a'] = true;
                flag = true;
            }
            c = '.';
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return flag;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; ++t)
    {
        cin >> h >> w;
        memset(map[0], '*', sizeof(char) * (w + 4));
        memset(map[1], '.', sizeof(char) * (w + 4));
        memset(map[h + 2], '.', sizeof(char) * (w + 4));
        memset(map[h + 3], '*', sizeof(char) * (w + 4));
        map[1][0] = map[1][w + 3] = '*';
        map[h + 2][0] = map[h + 2][w + 3] = '*';
        for (int i = 2; i < h + 2; ++i)
        {
            for (int j = 2; j < w + 2; ++j)
                cin >> map[i][j];
            map[i][0] = map[i][w + 3] = '*';
            map[i][1] = map[i][w + 2] = '.';
        }

        memset(key, false, sizeof(key));
        string k;
        cin >> k;
        if (k != "0")
            for (auto c : k)
                key[c - 'a'] = true;
        answer = 0;
        while (1)
        {
            bool found = bfs();
            if (!found)
                break;
        }
        cout << answer << endl;
    }
    return 0;
}