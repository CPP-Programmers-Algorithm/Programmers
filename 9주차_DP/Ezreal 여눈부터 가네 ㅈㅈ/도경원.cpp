#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int n, mod = 1'000'000'007;
	cin >> n;

	int dist[3][1516];						// dist[i][j]는 j자리면서 3으로 나눈 나머지가 i인 경우의 수
	
	dist[0][1] = 0;							// 1자리수의 경우의 수 지정
	
	dist[0][2] = 1;							// 2자리수를 초기로 잡는다
	dist[1][2] = 1; 
	dist[2][2] = 0; 

	for (int i = 3; i < n + 1; i++) {		//전의 자리수에서 값을 가져옴
		dist[0][i] = (dist[2][i - 1] + dist[1][i - 1]) % mod; 
		dist[1][i] = (dist[0][i - 1] + dist[2][i - 1]) % mod;
		dist[2][i] = (dist[1][i - 1] + dist[0][i - 1]) % mod;
	}

	cout << dist[0][n];
	return 0;
}


// 점화식
// dp[(i + 1) % 3][j] += dp[i][j - 1]
// dp[(i + 5) % 3][j] += dp[i][j - 1]
// 
//https://kangwlgns.tistory.com/17