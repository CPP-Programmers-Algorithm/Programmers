#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<deque>
#include<map>
#include<vector>
#include<cmath>
#include<climits>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<math.h>
#include<memory>
#include<sstream>

#define INF 0x3f3f3f3f
#define MAX 1001
#define MIN -1001
using namespace std;

int xSign[4] = { 0,1,-1,0 };
int ySign[4] = { 1,0,0,-1 };

struct Val {
	int cost;
	int depth;
};
vector<vector<int>> board;
vector<vector<int>> cost;
bool ans;
void DFS(int x, int y, int depth) {
	int temp = board[x][y];
	if (depth == 3) {
		if (cost[x][y] >= 2)
			ans = true;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int xAfter = x + xSign[i];
			int yAfter = y + ySign[i];
			if (xAfter >= 5 || yAfter >= 5 || xAfter < 0 || yAfter < 0)
				continue;
			if (board[xAfter][yAfter] == -1)
				continue;

			if (board[xAfter][yAfter] == 1) {
				cost[xAfter][yAfter] = max(cost[xAfter][yAfter], cost[x][y] + 1);
			}
			else {
				cost[xAfter][yAfter] = max(cost[xAfter][yAfter], cost[x][y]);
			}
			board[x][y] = -1;
			DFS(xAfter, yAfter, depth + 1);
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		vector<int> temp;
		vector<int> temp2;
		for (int j = 0; j < 5; j++) {
			int num;
			cin >> num;
			temp.push_back(num);
			temp2.push_back(0);
		}
		cost.push_back(temp2);
		board.push_back(temp);
	}
	int startX, startY;
	cin >> startX >> startY;
	DFS(startX, startY, 0);
	cout << ans;
}
