#include <string>
#include <vector>
#include<algorithm>
#include<deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	deque<string> cache;
	for (int i = 0; i < cities.size(); i++) {
		//�ҹ��ڷ� ���� ���� ����
		string cac = cities[i];
		for (int j = 0; j < cac.length(); j++) {
			cac[j] = tolower(cac[j]);
		}

		//ĳ�ÿ� ���� ���ð� �ִ��� Ȯ��
		bool isHit = false;
		int idx = 0;
		for (int j = 0; j < cache.size(); j++) {
			//���� ���ð� �ִٸ�
			if (cache[j] == cac) {
				isHit = true;
				idx = j;
				break;
			}
		}
		//Hit�� ���
		if (isHit) {
			cache.erase(cache.begin() + idx);
			answer += 1;
		}
		//miss�� ���
		else {
			if (cache.size() == cacheSize && cacheSize != 0)
				cache.pop_back();
			answer += 5;
		}
		//ĳ�� ������ 0�ʰ��� ��츸 ��������
		if (cacheSize > 0)
			cache.push_front(cac);
	}
	return answer;
}