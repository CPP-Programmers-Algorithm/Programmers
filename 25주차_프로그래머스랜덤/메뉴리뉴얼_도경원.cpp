#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/72411

// orders 배열의 각 원소는 크기가 2이상 10 이하인 문자열  -> 음식을 10개 초과로 시킬 수 없음

// index 는 음식의 수를 말함
// combination[3] -> 3가지로 만들 수 있는 조합
unordered_map<string, int> combination[11]; // 음식이름 , 횟수

int mxCount[11];

void comb(string str, int cnt, string result) {
	//경우의 수의 끝에 도달했을 때
	if (cnt == str.size()) {
		// num : 메뉴개수
		// result : 메뉴조합
		// 최대인지 확인
		int num = result.size();
		combination[num][result]++;

		// result 의 갯수 중 max
		mxCount[num] = max(mxCount[num], combination[num][result]);
		return;
	}

	// 조합
	// 이를 통해 조합할 수 있는 모든 수를 찾을 수 있다

	// 해당 문자 선택함
	// 해당 문자 선택하지 않음
	comb(str, cnt + 1, result + str[cnt]);
	comb(str, cnt + 1, result);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (auto order : orders) {
		// 조합 만들 때도 오름차순으로 만들어야 함
		sort(order.begin(), order.end());
		comb(order, 0, "");
	}

	// course 에 맞는 것을 뽑아서 넣음
	// combination 중 갯수가 맞는 것만 가져온다
	// 갯수별 최대값을 저장해 놓은 것과 같은 값을 가져온다
	
	// 2명 이상의 손님이 시켜야 함
	for (auto num: course){
		for (auto x : combination[num]) { 
			if (x.second == mxCount[num] && x.second >= 2) {
				answer.push_back(x.first);
			}
		}
	}

	// 결과도 오름차순 정렬
	sort(answer.begin(), answer.end());
	return answer;
}
