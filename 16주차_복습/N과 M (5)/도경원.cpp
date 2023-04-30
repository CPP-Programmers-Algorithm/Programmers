#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int arr[10];
int num[10];
int check[10];

void dfs(int len) {
	//종료조건
	if (len == m) { //깊이가 왔을 때 프린트한다
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//배역구성
	for (int i = 0;i < n;i++) {
		if (check[i] == 0) {
			arr[len] = num[i]; //배열선언
			check[i] = 1; //중복막기
			dfs(len + 1);
			check[i] = 0; //중복풀기
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);
	dfs(0);

	return 0;
}