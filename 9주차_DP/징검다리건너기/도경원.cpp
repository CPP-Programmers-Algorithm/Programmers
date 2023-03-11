#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> stones, int k) {
	int ans = 987654321;
	deque<pair<int, int>> dq;

	for (int i = 0; i < stones.size(); i++) {								 // ��� �� Ž��
		int st = i - k + 1;													 // �������� idx

		while (!dq.empty() && dq.front().second < st) dq.pop_front();		 // ���� ������ ������ ���ٸ�
		while (!dq.empty() && dq.back().first < stones[i]) dq.pop_back();	 // ����� �Ŀ��� �ִ밪 ���ɼ� ���� - ���� ���� �ֺ��ٵ� �۴ٸ� �ڿ������� ������

		dq.push_back(make_pair(stones[i], i));								// ���� �ڵ� ������ push front�� ���� ��Ȱ��
		if (i >= k - 1 && dq.front().first < ans) ans = dq.front().first;	// idx�� k�� ��� �����ϴ� �������� �����
	}
	return ans;
}

// �����ؼ� k���� ������� 0�� �Ǵ� ���� ���� ����
// ���� Ž������ ������� �־��� ����(k)�� ������ ���� ������ ���̶�� �����ϰ� Ž��
// ������ ���̶�� �����ϸ� ������ ������ k�� �� �� �� ���� ū ���� �ǳ� �� �ִ� �ο��� ���� �ȴ�

// Ư�� ������� ������ ������� ������ ���������� �ִ� = �ش� ������ ������ �� �ִ� �ο�
// �������� Ž���� �Ŀ� �� �� ���� ���� ���� �����ؾ� �Ѵ�


// deque �̿�
// Ž���������� �ִ��� �� �տ� ����
// �Ŀ� �ٸ� �������� �ִ밪�� �� �� �ִ°� ����
// �ĺ��� �ƴ϶�� ����
// �ĺ���� �� �ڿ� ����

//https://yabmoons.tistory.com/632