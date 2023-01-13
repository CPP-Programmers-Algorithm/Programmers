#include <string>
#include <vector>
#include<algorithm>
#include<deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	deque<string> cache;
	for (int i = 0; i < cities.size(); i++) {
		//소문자로 현재 도시 저장
		string cac = cities[i];
		for (int j = 0; j < cac.length(); j++) {
			cac[j] = tolower(cac[j]);
		}

		//캐시에 현재 도시가 있는지 확인
		bool isHit = false;
		int idx = 0;
		for (int j = 0; j < cache.size(); j++) {
			//현재 도시가 있다면
			if (cache[j] == cac) {
				isHit = true;
				idx = j;
				break;
			}
		}
		//Hit의 경우
		if (isHit) {
			cache.erase(cache.begin() + idx);
			answer += 1;
		}
		//miss의 경우
		else {
			if (cache.size() == cacheSize && cacheSize != 0)
				cache.pop_back();
			answer += 5;
		}
		//캐시 공간이 0초과일 경우만 저장하자
		if (cacheSize > 0)
			cache.push_front(cac);
	}
	return answer;
}