#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> island(101);

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2]; // 비용 비교
}

int findParent(int idx) {
	if (island[idx] == idx)
		return idx;
	return island[idx] = findParent(island[idx]);
}

int solution(int n, vector<vector<int>> costs) {
	int ans = 0;

	// 섬저장
	for (int i = 0; i < n; i++){
		island[i] = i;
	}
	// 비용이 적은 순으로 정렬
	sort(costs.begin(), costs.end(), cmp);

	for (int i = 0; i < costs.size(); i++)
	{
		int st = findParent(costs[i][0]);
		int en = findParent(costs[i][1]);
		int cost = costs[i][2];

		// cycle이 만들어지지 않으면 다리 추가
		if (st != en) {
			ans += cost;
			island[en] = st;
		}
	}
	return ans;
}