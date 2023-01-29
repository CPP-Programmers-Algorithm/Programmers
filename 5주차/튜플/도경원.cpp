#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream>

#define pii pair<int,int>
using namespace std;

// value 값을 비교하는 함수
bool cmp(const pii& a, const pii& b) {
	if (a.second == b.second) return a.first > b.first;		// second가 value
	return a.second > b.second;								// value가 다르다면 비교결과 반환
}


vector <int> solution(string s) {
	vector<int> answer;
	map<int, int> m;									 // key value 로 저장됨

	string tmp;
	for (int i = 1; i < s.length() - 1; i++)
	{
		if (s[i] != '{' && s[i] != '}' && s[i] != ',')	 // 숫자일 경우
		{
			tmp += s[i];
			if (s[i + 1] == ',' || s[i + 1] == '}') {
				m[stoi(tmp)]++;							  // 카운팅 : 해당 키의 value 증가
			}
			else continue;								  // 기호가 나오지 않았다면 tmp에 계속 담음
		}
		tmp = "";
	}

	// 여기까지 하면 
	// map key   : tuple의 요소
	// map value : 요소가 등장한 횟수

	// value 기반 정렬
	vector<pii> vec(m.begin(), m.end());	// map 기반 vec 형성
	sort(vec.begin(), vec.end(), cmp);		// cmp에서 value비교를 넣었으니 vector가 value기준으로 정렬됨

	for (auto num : vec) {
		answer.push_back(num.first);		//emplace_back을 써도 됨;
	}
	
	return answer;
}

int main() {
	string input;
	cin >> input;
	solution(input);
}