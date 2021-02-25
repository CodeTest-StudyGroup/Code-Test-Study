#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int x1;
    int y1;
    int x2;
    int y2;
    Node (int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

vector<Node> getNextPos (Node pos, vector <vector <int> > board) {
    vector <Node> nextPos;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    for (int i = 0; i < 4; i++) {
        int nx1 = pos.x1 + dx[i];
        int ny1 = pos.y1 + dy[i];
        int nx2 = pos.x2 + dx[i];
        int ny2 = pos.y2 + dy[i];
        
        if (board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
            nextPos.push_back(Node(nx1, ny1, nx2, ny2));
        }
    }
    
    int hor_ver[2] = {-1, 1};
    //현재 로봇이 가로로 놓여 있음
    if (pos.x1 == pos.x2) {
        for (int i = 0; i < 2; i++) {
            if (board[pos.x1 + hor_ver[i]][pos.y1] == 0 && board[pos.x2 + hor_ver[i]][pos.y2] == 0) {
                nextPos.push_back(Node(pos.x1, pos.y1, pos.x1 + hor_ver[i], pos.y1));
                nextPos.push_back(Node(pos.x2, pos.y2, pos.x2 + hor_ver[i], pos.y2));
            }
        }
    }
    //현재 로봇이 세로로 놓여 있음
    if (pos.y1 == pos.y2) {
        for (int i = 0; i < 2; i++) {
            if (board[pos.x1][pos.y1 + hor_ver[i]] == 0 && board[pos.x2][pos.y2 + hor_ver[i]] == 0) {
                nextPos.push_back(Node(pos.x1, pos.y1, pos.x1, pos.y1 + hor_ver[i]));
                nextPos.push_back(Node(pos.x2, pos.y2, pos.x2, pos.y2 + hor_ver[i]));
            }
        }
    }
    
    return nextPos;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    vector <vector <int> > newBoard (n+2, vector<int>(n+2, 1) );
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newBoard[i + 1][j + 1] = board[i][j];
        }
    }
    
    queue<pair<Node, int> > q;
    vector<Node> visited;
    
    Node pos = Node(1, 1, 1, 2);
    q.push({pos, 0});
    visited.push_back(pos);
    
    while (!q.empty()) {
        Node pos = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        if ((pos.x1 == n && pos.y1 == n) || (pos.x2 == n && pos.y2 == n))
            return cost;
        
        vector<Node> nextPos = getNextPos(pos, newBoard);
        for (int i = 0; i < nextPos.size(); i++) {
            bool check = true;
            Node pos = nextPos[i];
            for (int j = 0; j < visited.size(); j++) {
                if (pos.x1 == visited[j].x1 && pos.y1 == visited[j].y1 && pos.x2 == visited[j].x2 && pos.y2 == visited[j].y2) {
                    check = false;
                    break;
                }
            }
            if (check) {
                q.push({pos, cost + 1});
                visited.push_back(pos);
            }
        }
    }
    
    return 0;
}