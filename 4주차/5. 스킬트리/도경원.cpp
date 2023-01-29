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
				if (y == a) { // 겹치는 부분 검사
					s += a;   // 스킬트리에 있다면 string에 넣어준다
					break;    // 중복되는 것은 없으니 찾았다면 break
				}
			}
		}
		cout << s << '\n';
		int len = s.size();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (skill[i] == s[i]) {		// skill과 비교한다 뒤는 빠질 수 있지만 앞에 것들은 반드시 빠질 수 없다
				cnt++;					// 그래서 i번째를 비교하면 된다
			}
		}
		if (cnt == len) {
			answer++;					// 길이가 같다면 모두 순서에 맞는 것이다
		}
	}
	return answer;
}