#include<iostream>
#include<vector>
#include<queue>

using namespace std;


vector<bool> v(101, false);
vector<vector<bool>> visited(101, v);

int xSign[4] = { 1,-1,0,0 };
int ySign[4] = { 0,0,1,-1 };

//cost까지 넣어서 계산하니 효율성 검사 통과
struct que {
    int x;
    int y;
    int cost;
};
int solution(vector<vector<int> > maps)
{
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 0)
                visited[j][i] = true;
        }
    }

    int answer = -1;
    visited[0][0] = true;

    queue<que> q;
    q.push({ 0,0,1 });
    while (!q.empty()) {
        que qFirst = q.front();
        if (qFirst.x == maps[0].size() - 1 && qFirst.y == maps.size() - 1) {
            answer = qFirst.cost;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int afterX = qFirst.x + xSign[i] < 0 || qFirst.x + xSign[i] >= maps[0].size() ? qFirst.x : qFirst.x + xSign[i];
            int afterY = qFirst.y + ySign[i] < 0 || qFirst.y + ySign[i] >= maps.size() ? qFirst.y : qFirst.y + ySign[i];

            if ((afterX == qFirst.x && afterY == qFirst.y) ||
                visited[afterX][afterY]) continue;

            visited[afterX][afterY] = true;

            q.push({ afterX, afterY,qFirst.cost + 1 });
        }
    }


    return answer;
}
