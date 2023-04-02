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
#include<unordered_map>
#define INF 0x3f3f3f3f/3
#define endl "\n"
using namespace std;

vector<vector<int>> lockBoard;
int n;
int m;
int holeCnt = 0;
bool IsSameCheck(vector<vector<int>>& key, pair<int, int> firstKey, pair<int, int> firstLock) {

	int visitedCnt = 0;
	pair<int, int> diff = { firstKey.first - firstLock.first, firstKey.second - firstLock.second };
	for (int i = firstLock.second; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int nextX = j + diff.first;
			int nextY = i + diff.second;
			if (nextX >= m || nextY >= m || nextX < 0 || nextY < 0)
				continue;
			if (lockBoard[i][j] == key[nextY][nextX])
				return false;
			if (lockBoard[i][j] == 0)
				visitedCnt++;
		}
	}
	if (holeCnt != visitedCnt)
		return false;
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	lockBoard = lock;

	n = lock.size();
	m = key.size();

	//lock 검사
	pair<int, int> firstPos = { -1,-1 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lock[i][j] == 0) {
				if (holeCnt == 0) {
					firstPos = { j,i };
				}
				holeCnt++;
			}
		}
	}

	//key 검사
	bool isFind = false;
	for (int i = 0; i < m; i++) {
		if (isFind)
			break;
		for (int j = 0; j < m; j++) {
			if (key[i][j] == 1) {
				isFind = true;
				break;
			}
		}
	}

	//홈이 없는 것
	if (holeCnt == 0)
		return true;
	//돌기가 없는것
	if (!isFind)
		return false;

	//회전 돌리기
	vector<vector<int>> newVector(m, vector<int>(m, 0));
	for (int t = 0; t < 4; t++) {

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (key[i][j] == 1) {
					if (IsSameCheck(key, pair<int, int>{j, i}, firstPos))
						return true;
				}
			}
		}
		//돌리기
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				newVector[i][j] = key[m - (j + 1)][i];
			}
		}
		key = newVector;
	}

	return false;
}