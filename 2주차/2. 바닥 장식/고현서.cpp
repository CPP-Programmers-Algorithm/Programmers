#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> visited;
vector<vector<char>> floorMap;
int n, m;
int ans;
void DFS(char axis, int x, int y, int end) {
	if (axis == 'x') {
		if (x + 1 >= end) {
			if (floorMap[y][x] == '-')
				ans++;
			return;
		}
		if (floorMap[y][x] == '-') {
			if (floorMap[y][x + 1] == '|') {
				ans++;
			}
		}
		DFS(axis, x + 1, y, end);
	}
	else {
		if (y + 1 >= end) {
			if (floorMap[y][x] == '|')
				ans++;
			return;
		}
		if (floorMap[y][x] == '|') {
			if (floorMap[y + 1][x] == '-') {
				ans++;
			}
		}
		DFS(axis, x, y + 1, end);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			temp.push_back(ch);
		}
		floorMap.push_back(temp);
	}

	for (int i = 0; i < floorMap.size(); i++) {
		DFS('x', 0, i, m);
	}
	for (int i = 0; i < floorMap[0].size(); i++) {
		DFS('y', i, 0, n);
	}
	cout << ans;
}
