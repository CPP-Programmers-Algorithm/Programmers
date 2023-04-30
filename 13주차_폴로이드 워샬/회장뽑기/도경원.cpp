#include <iostream>
#include <algorithm>
#define maxn 55

using namespace std;


int dst[maxn][maxn], score[maxn];
int arr[maxn], cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);






	int n; cin >> n;
	int ans = maxn;

	// input
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			dst[i][j] = maxn; // 최소값을 갱신하기 때문에

	while (true) {
		int s, e;cin >> s >> e;
		if (s < 0) break;
		dst[s][e] = dst[e][s] = 1; //간선연결
	}

	// Floyd
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (dst[i][j] > dst[i][k] + dst[k][j]) {
					dst[i][j] = dst[i][k] + dst[k][j]; //k를 지나 도착하는 최소값갱신
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= n; ++j){
			if (i != j) {
				if (score[i] < dst[i][j]) {
					score[i] = dst[i][j]; // 개인별 최고점수찾기
				}
			}
		}
		if (ans > score[i])ans = score[i]; // 회원들 중 최소점수찾기
	}
	
	// output
	for (int i = 1; i <= n; ++i){
		if (score[i] == ans) { // 중복되는 회원저장
			arr[cnt++] = i;
		}
	}
	cout << ans <<' '<< cnt << '\n';
	for (int i = 0; i < cnt; ++i) { // 출력
		cout << arr[i]<<' ';
	}
}

