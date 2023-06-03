#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 2000

//ī�����

// Ʋ���� ī�ǰ����� ����
// dp��� �����Ǿ��µ� ���� 2*maxī�� ����� ���̺��� ��������
// ������ �����ϴ� �� ����, dp�� ����� ���� ������ dp���̺��� ���μ��� Ȥ�� ���̷� �����ϱ�

int N;
int left_card[MAXN + 10];
int right_card[MAXN + 10];
int M[MAXN][MAXN];

void Input() { //ī������ �ʱ�ȭ
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> left_card[i];
	for (int i = 0; i < N; i++)
		cin >> right_card[i];
}
int DP(int left, int right) {
	if (left == N || right == N) return 0;

	if (M[left][right] != -1) return M[left][right]; // �̹� ���� ������ �� ���� �ش� -> �� �� ����� ���� �ι� �̻� �ݺ����� ������

	M[left][right] = 0;
	// ���ǿ� ���� �ݵ�� ������ ī�� ������ ��� -> ������ ī�� ��ŭ ����
	if (right_card[right] < left_card[left]) {
		M[left][right] += right_card[right] + DP(left, right + 1); // dp �Ű������� idx�� �������� �����Ѵ�
	}
	// ������ ������ ���� �Ѵ� ������ ��� 
	// �� �� ū ���� �����´�
	else {
		M[left][right] += max(DP(left + 1, right), DP(left + 1, right + 1)); // �� ��� ���� ���ǿ� ���� ������ ���� ���ϹǷ� �ε����� �̵���Ų��
	}																		
	return M[left][right];
}
int main() {
	Input();

	memset(M, -1, sizeof(M));
	cout << DP(0, 0);;
	return 0;
}

// ������ ��
// �ݵ�� ������ �ϴ� ��츦 if������ ���ϰ�
// ������ �� �ִ� ����� ���� dp�� max�� �������� ã�´�

// �򰥸� �� �ִ� ����
// ó�� dp ������ �� �� �ٽ������� ���� ���ϴ� �� ������ dp�� ���ο��� �� ���� �����ִ� ������ ���� ���ϱ� ������ ���� �����Ѵ�

// �ǹ���
// ���ʿ� ���������ϰ� ū ���� ������ �����? ��� ����� ���� dx�ε��� �͵� �ƴѵ�