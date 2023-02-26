#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	int gems_size = gems.size();
	int min_dist = 100001;

	unordered_map<string, int> list;		//������ ����, ������ ����
	unordered_set<string> s_temp;			//���� �� ���Ե� ���� �������

	for (int i = 0; i < gems_size; i++) { // ������ ������ ���ϱ� ���� �κ�
		s_temp.insert(gems[i]);
	}
	int kind = s_temp.size(); 
	int idx_r = 0, idx_l = 0;

	while (true) {
		if (list.size() >= kind)		 // ��� ��� ������ ������ �̵��ؾ� �Ѵ�
		{
			list[gems[idx_l]]--;		 // �ش� key�� �ִ� value���� �ϳ� ���δ�

			if (list[gems[idx_l]] == 0)  // 0�̶�� �ش纸���� �ϳ��� ������ �־��� ��
			{
				list.erase(gems[idx_l]); // l�� �����͸� �ű� ���̾ �����ش� - ������ ����� ��Ȱ�� �ϸ� �ȴ�
			}
			idx_l++;					 // ���� ������ ����
		}
		else if (idx_r == gems_size) {	 // ������ �����Ͱ� ���� ���������� �����Ѵ�
			break;
		}
		else {							 // < ���Ⱑ ó�� ������ �� >
			list[gems[idx_r]]++;		 // list�� ����� kind�� ������ ������ �־��� - ���̶� �ߺ����x
			idx_r++;					 // ������ �����͸� ����
		}

		if (list.size() == kind) {		 // �ʿ��� ������ ��� ���Դٴ� ��
			int temp = idx_r - idx_l;	 // ������ ���Ѵ�
			if (temp < min_dist) {		 // ���� ���� ������ ���� �������� �۴ٸ�
				answer.clear();					// answer�� �������ش�
				answer.push_back(idx_l + 1);
				answer.push_back(idx_r);
				min_dist = temp;				// �ּұ��̸� �������ش�
			}
		}
	}
	return answer;
}







//https://blog.naver.com/kks227/220795165570
//https://novemberfirst.tistory.com/54