#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define MOD 1000000007

using namespace std;
int d[1001][1001], n, m;

int dp(int i, int j) {
	if (i < 1 || j < 1)   return 0;
	if (i == 1 && j == 1) return 1;

	int &ret = d[i][j];
	if (ret != -1) return ret;
	
	ret = 0;					// 세 갈래의 길로 퍼진다 // 원점을 만나면 1을 가져온다
	ret = ((dp(i, j - 1) + dp(i - 1, j)) % MOD + dp(i - 1, j - 1)) % MOD;// 윗자리는 어짜피 따로 더해질 수도 있으니 넘기전에 처리
	
	return ret;
}

int main() {

	memset(d, -1, sizeof(d));
	cin >> n >> m;
	cout << dp(n, m);
}