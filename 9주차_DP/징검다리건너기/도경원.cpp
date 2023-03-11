#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> stones, int k) {
	int ans = 987654321;
	deque<pair<int, int>> dq;

	for (int i = 0; i < stones.size(); i++) {								 // 모든 돌 탐색
		int st = i - k + 1;													 // 구간시작 idx

		while (!dq.empty() && dq.front().second < st) dq.pop_front();		 // 현재 구간에 영향이 없다면
		while (!dq.empty() && dq.back().first < stones[i]) dq.pop_back();	 // 현재와 후에도 최대값 가능성 없음 - 새로 들어온 애보다도 작다면 뒤에서부터 빼간다

		dq.push_back(make_pair(stones[i], i));								// 위의 코드 때문에 push front와 같은 역활함
		if (i >= k - 1 && dq.front().first < ans) ans = dq.front().first;	// idx가 k를 모두 포함하는 구간에서 실행됨
	}
	return ans;
}

// 연속해서 k개의 디딤돌이 0이 되는 가장 빠른 구간
// 현재 탐색중인 디딤돌이 주어진 길이(k)를 가지는 가장 마지막 돌이라고 가정하고 탐색
// 마지막 돌이라고 가정하면 마지막 돌에서 k를 뺀 것 중 가장 큰 것이 건널 수 있는 인원의 수가 된다

// 특정 디딤돌을 마지막 디딤돌로 가지는 구간에서의 최댓값 = 해당 구간을 지나갈 수 있는 인원
// 구간들을 탐색한 후에 그 중 가장 작은 답을 선택해야 한다


// deque 이용
// 탐색구간에서 최댓값을 맨 앞에 삽입
// 후에 다른 구간에서 최대값이 될 수 있는가 생각
// 후보가 아니라면 삭제
// 후보라면 맨 뒤에 삽입

//https://yabmoons.tistory.com/632