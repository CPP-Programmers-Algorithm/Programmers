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

int xSign[2] = { 0,1 };
int ySign[2] = { 1,0 };

vector<vector<int>> gameMap;
int n;
int DFS(int x, int y) {
	if (gameMap[y][x] == -1)
		return 1;
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		if (x + xSign[i] * gameMap[x][y] < n && y + ySign[i] * gameMap[x][y] < n
			&& (x < x + xSign[i] * gameMap[x][y]
				|| y < y + ySign[i] * gameMap[x][y]))
			ans = max(ans, DFS(x + xSign[i] * gameMap[x][y], y + ySign[i] * gameMap[x][y]));
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			temp.push_back(num);
		}
		gameMap.push_back(temp);
	}
	int a = DFS(0, 0);
	if (a == 1)
		cout << "HaruHaru";
	else
		cout << "Hing";
}
