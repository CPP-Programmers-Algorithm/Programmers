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
#define INF 0x3f3f3f3f/3
#define endl "\n"
using namespace std;

int solution(string s) {
	int answer = s.length();
	for (int i = 1; i <= s.length() / 2; i++) {
		int cnt = 1;
		int totalMinus = 0;
		int countNum = 0;
		string findStr = s.substr(0, i);
		for (int j = i; j < s.length(); j += i) {
			string str2 = s.substr(j, i);
			//비교하는 문자랑 같은 경우 cnt증가
			if (findStr == str2)
				cnt++;
			else {
				//압축할 string 업데이트
				findStr = str2;
				//압축의 대표할 str 하나만 빼고 나머지 제외
				totalMinus += cnt - 1;
				//앞에 갯수를 넣을 숫자 갯수 하나 증가
				if (cnt > 1)
					countNum += log10(cnt) + 1;
				//갯수 초기화
				cnt = 1;
			}
		}
		if (cnt > 1) {
			//압축의 대표할 str 하나만 빼고 나머지 제외
			totalMinus += cnt - 1;
			//앞에 갯수를 넣을 숫자 갯수 하나 증가
			countNum += log10(cnt) + 1;
		}
		answer = min(answer, (int)s.length() - (totalMinus * i) + countNum);
	}
	return answer;
}