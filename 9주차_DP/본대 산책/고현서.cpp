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
using namespace std;


#define MOD 1000000007
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
}
vector<int> roadInfo[9] =
{
	{},
	{2,3},
	{1,4,3},
	{1,2,4,5},
	{2,3,5,6},
	{3,4,6,8},
	{4,5,7},
	{6,8},
	{5,7}
};
int d;
//각 장소가 몇번만에 가는 경우의 수 
long long dp[9][100001];
int isVisited[9][100001];
void DP() {
	//x, depth
	queue<pair<int, int>> q;
	dp[1][0] = 1;
	q.push({ 1,0 });
	while (!q.empty()) {
		int frontX = q.front().first;
		int frontDepth = q.front().second;
		q.pop();
		for (int i = 0; i < roadInfo[frontX].size(); i++) {
			dp[roadInfo[frontX][i]][frontDepth + 1] += dp[frontX][frontDepth];
			dp[roadInfo[frontX][i]][frontDepth + 1] %= MOD;
			if (frontDepth + 1 >= d)
				continue;
			if (!isVisited[roadInfo[frontX][i]][frontDepth + 1]) {
				q.push({ roadInfo[frontX][i],frontDepth + 1 });
				isVisited[roadInfo[frontX][i]][frontDepth + 1] = true;
			}
		}
	}
}
int main() {
	init();
	cin >> d;
	DP();
	cout << dp[1][d];
}