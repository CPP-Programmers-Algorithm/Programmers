#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

typedef long long ll;

using namespace std;

ll arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, M; // N : ������, M : ��緹���� ����
	cin >> N >> M;

	ll sum = 0, low = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i]; // ��� ������ ���̸� ���� ���� high�� �ǰ�
		low = max(low, arr[i]); // �� ���� �� ���� �� ���� low�� �ȴ�
	}

	ll high = sum;

	while (low <= high) {
		ll cnt = 0, tempSum = 0; // cnt : ���Ǵ� ��緹���� �� // tempSum : �� ��緹�̿� ���� ��������� ��
		ll mid = (low + high) / 2;

		for (int i = 0; i < N; i++) // �ݺ����� �Ἥ ����� ���� �� ������ �ð����⵵�� aN�̴�
		{
			if (tempSum + arr[i] > mid) { // ���� ���̺� ������ �ּҰ��� �Ѿ�� ���� ���̺� �����ϴ� ��
				tempSum = 0;
				cnt += 1;
			}
			tempSum += arr[i]; // ���̺� ��������
		}
		if (tempSum != 0) cnt += 1; // ��緹���� ũ�Ⱑ ������ ũ�⺸�� �۾Ƽ� 1 ���� ����Ű�� 1����

		if (cnt <= M) { // �����Ǵ� ���̺� ������ ���ڸ��ٸ� high ������
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << low;
	return 0;
}
//ref : https://chanhuiseok.github.io/posts/baek-22/