#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/72411

// orders �迭�� �� ���Ҵ� ũ�Ⱑ 2�̻� 10 ������ ���ڿ�  -> ������ 10�� �ʰ��� ��ų �� ����

// index �� ������ ���� ����
// combination[3] -> 3������ ���� �� �ִ� ����
unordered_map<string, int> combination[11]; // �����̸� , Ƚ��

int mxCount[11];

void comb(string str, int cnt, string result) {
	//����� ���� ���� �������� ��
	if (cnt == str.size()) {
		// num : �޴�����
		// result : �޴�����
		// �ִ����� Ȯ��
		int num = result.size();
		combination[num][result]++;

		// result �� ���� �� max
		mxCount[num] = max(mxCount[num], combination[num][result]);
		return;
	}

	// ����
	// �̸� ���� ������ �� �ִ� ��� ���� ã�� �� �ִ�

	// �ش� ���� ������
	// �ش� ���� �������� ����
	comb(str, cnt + 1, result + str[cnt]);
	comb(str, cnt + 1, result);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (auto order : orders) {
		// ���� ���� ���� ������������ ������ ��
		sort(order.begin(), order.end());
		comb(order, 0, "");
	}

	// course �� �´� ���� �̾Ƽ� ����
	// combination �� ������ �´� �͸� �����´�
	// ������ �ִ밪�� ������ ���� �Ͱ� ���� ���� �����´�
	
	// 2�� �̻��� �մ��� ���Ѿ� ��
	for (auto num: course){
		for (auto x : combination[num]) { 
			if (x.second == mxCount[num] && x.second >= 2) {
				answer.push_back(x.first);
			}
		}
	}

	// ����� �������� ����
	sort(answer.begin(), answer.end());
	return answer;
}
