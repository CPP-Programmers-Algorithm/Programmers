#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int arr[10];
int num[10];
int check[10];

void dfs(int len) {
	//��������
	if (len == m) { //���̰� ���� �� ����Ʈ�Ѵ�
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//�迪����
	for (int i = 0;i < n;i++) {
		if (check[i] == 0) {
			arr[len] = num[i]; //�迭����
			check[i] = 1; //�ߺ�����
			dfs(len + 1);
			check[i] = 0; //�ߺ�Ǯ��
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