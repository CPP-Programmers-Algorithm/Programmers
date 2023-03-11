# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

// �׸����� ����� ���� ������ ������ �´� ������ �� �Ǵ��� ���� �ʴ´ٴ� ���̴�
// �̶��� �ͷ���?�� ���� ã�ƾ� �� �� ����
// �� ����� ���������� ����߰ڴ� -> ������

int main() {
	int N, start, end;
	vector<pair<int, int>> meetings;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		meetings.push_back(make_pair(end, start)); // end�������� ������ ��
	}

	sort(meetings.begin(), meetings.end());		// end���� ����

	int time = meetings[0].first;		// ù��°�� ������ �ֱ�
	int count = 1;						// end�������� ���ĵǾ� ������ �� ���� ������
	for (int i = 1; i < N; i++)
	{
		if (meetings[i].second >= time) { // ���۽ð��� ���� end�ð����� ũ�ٸ� ���
			time = meetings[i].first;	  // end �������� ���ĵǾ� ������ ���� ����ũ�� ȸ�ǰ� ����
			count++;					  // end �ð� ������Ʈ, ȸ�Ǽ� ������Ʈ
		}
	}
	cout << count;
}

// ref : https://cocoon1787.tistory.com/147