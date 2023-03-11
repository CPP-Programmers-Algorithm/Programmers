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
	//몇 종류의 보석이 있는지 확인
	for (int i = 0; i < gems.size(); i++) {
		auto iter = m.find(gems[i]);
		if (iter == m.end()) {
			m.insert({ gems[i], 0 });
			gemCnt++;
		}
	}
	for (int i = 0; i < gems.size(); i++) {
		cnt++;
		//새로운 종류의 보석이 나왔을 경우
		if (m[gems[i]] == 0)
			valCnt++;
		m[gems[i]]++;
		//모든 종류의 보석을 모았을 경우
		if (valCnt == gemCnt) {
			//앞의 보석들 중 중복되는 것을 최대한 빼자
			for (int j = start - 1; j <= i; j++) {
				//유일한 보석이 사라지는 곳 -> 최대한 뺐을 경우의 위치
				if (m[gems[j]] - 1 == 0) {
					//갯수가 더 작다면 -> 저장 및 업데이트
					if (minCnt > cnt) {
						minCnt = cnt;
						startEnd = { start, i + 1 };
					}
					//이 친구를 제외하고 -> 즉 한 종류의 보석을 없애고 뒤의 보석들을 탐색해서 새로운 꾸러미를 찾아보자
					m[gems[j]]--;
					cnt--;
					start++;
					valCnt--;

					break;
				}
				//앞으로 당기면서 중복 제거
				m[gems[j]]--;
				cnt--;
				start++;
			}
		}
	}

	return { startEnd.first, startEnd.second };
}