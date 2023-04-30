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
			dst[i][j] = maxn; // �ּҰ��� �����ϱ� ������

	while (true) {
		int s, e;cin >> s >> e;
		if (s < 0) break;
		dst[s][e] = dst[e][s] = 1; //��������
	}

	// Floyd
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (dst[i][j] > dst[i][k] + dst[k][j]) {
					dst[i][j] = dst[i][k] + dst[k][j]; //k�� ���� �����ϴ� �ּҰ�����
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= n; ++j){
			if (i != j) {
				if (score[i] < dst[i][j]) {
					score[i] = dst[i][j]; // ���κ� �ְ�����ã��
				}
			}
		}
		if (ans > score[i])ans = score[i]; // ȸ���� �� �ּ�����ã��
	}
	
	// output
	for (int i = 1; i <= n; ++i){
		if (score[i] == ans) { // �ߺ��Ǵ� ȸ������
			arr[cnt++] = i;
		}
	}
	cout << ans <<' '<< cnt << '\n';
	for (int i = 0; i < cnt; ++i) { // ���
		cout << arr[i]<<' ';
	}
}

