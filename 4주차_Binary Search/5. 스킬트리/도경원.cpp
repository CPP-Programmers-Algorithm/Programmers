#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (auto x : skill_trees) {
		string s = "";
		for (auto y : x) {
			for (auto a : skill) {
				if (y == a) { // ��ġ�� �κ� �˻�
					s += a;   // ��ųƮ���� �ִٸ� string�� �־��ش�
					break;    // �ߺ��Ǵ� ���� ������ ã�Ҵٸ� break
				}
			}
		}
		cout << s << '\n';
		int len = s.size();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (skill[i] == s[i]) {		// skill�� ���Ѵ� �ڴ� ���� �� ������ �տ� �͵��� �ݵ�� ���� �� ����
				cnt++;					// �׷��� i��°�� ���ϸ� �ȴ�
			}
		}
		if (cnt == len) {
			answer++;					// ���̰� ���ٸ� ��� ������ �´� ���̴�
		}
	}
	return answer;
}