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
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;

int xSign[2] = { 1,0 };
int ySign[2] = { 0,1 };
int num1 = 0;
int num0 = 0;
vector<vector<int>> arrTemp;
bool Searching(int startX, int startY, int size) {
	int init = arrTemp[startY][startX];

	for (int i = startY; i < startY + size; i++) {
		for (int j = startX; j < startX + size; j++) {
			if (arrTemp[i][j] != init)
				return false;
		}
	}
	return true;
}
vector<int> solution(vector<vector<int>> arr) {
	arrTemp = arr;
	vector<int> answer;
	//first -> ½ÃÀÛÁ¡ ÁÂÇ¥
	//second -> ¸îÄ­ Å½»ö?
	queue<pair<pair<int, int>, int>> searchSign;
	int n = arr.size();
	searchSign.push({ { 0,0 },n });
	while (!searchSign.empty()) {
		int frontY = searchSign.front().first.first;
		int frontX = searchSign.front().first.second;
		int frontSize = searchSign.front().second;
		searchSign.pop();
		if (frontSize == 1) {
			arr[frontY][frontX] == 1 ? num1++ : num0++;
			continue;
		}
		if (Searching(frontX, frontY, frontSize)) {
			arr[frontY][frontX] == 1 ? num1++ : num0++;
		}
		else {
			searchSign.push({ { frontY,frontX },frontSize / 2 });
			searchSign.push({ {frontY + frontSize / 2,frontX }, frontSize / 2 });
			searchSign.push({ { frontY,frontX + frontSize / 2 }, frontSize / 2 });
			searchSign.push({ { frontY + frontSize / 2, frontX + frontSize / 2 },frontSize / 2 });
		}
	}
	return answer = { num0, num1 };
}