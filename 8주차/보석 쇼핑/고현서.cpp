#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<deque>
#include<map>
#include<vector>
#include<cmath>
#include<climits>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<math.h>
#include<memory>
#include<sstream>
#include<unordered_map>
#define INF 0x3f3f3f3f
using namespace std;

unordered_map<string, int> m;
vector<int> solution(vector<string> gems) {
	vector<int> answer;
	pair<int, int> startEnd;
	int start = 1;
	int cnt = 0;
	int minCnt = gems.size() + 1;
	int valCnt = 0;
	int gemCnt = 0;
	//�� ������ ������ �ִ��� Ȯ��
	for (int i = 0; i < gems.size(); i++) {
		auto iter = m.find(gems[i]);
		if (iter == m.end()) {
			m.insert({ gems[i], 0 });
			gemCnt++;
		}
	}
	for (int i = 0; i < gems.size(); i++) {
		cnt++;
		//���ο� ������ ������ ������ ���
		if (m[gems[i]] == 0)
			valCnt++;
		m[gems[i]]++;
		//��� ������ ������ ����� ���
		if (valCnt == gemCnt) {
			//���� ������ �� �ߺ��Ǵ� ���� �ִ��� ����
			for (int j = start - 1; j <= i; j++) {
				//������ ������ ������� �� -> �ִ��� ���� ����� ��ġ
				if (m[gems[j]] - 1 == 0) {
					//������ �� �۴ٸ� -> ���� �� ������Ʈ
					if (minCnt > cnt) {
						minCnt = cnt;
						startEnd = { start, i + 1 };
					}
					//�� ģ���� �����ϰ� -> �� �� ������ ������ ���ְ� ���� �������� Ž���ؼ� ���ο� �ٷ��̸� ã�ƺ���
					m[gems[j]]--;
					cnt--;
					start++;
					valCnt--;

					break;
				}
				//������ ���鼭 �ߺ� ����
				m[gems[j]]--;
				cnt--;
				start++;
			}
		}
	}

	return { startEnd.first, startEnd.second };
}