# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

// 그리디의 어려운 점은 생각한 가정이 맞는 것인지 잘 판단이 서지 않는다는 것이다
// 이때는 귀류법?을 통해 찾아야 할 것 같다
// 이 방법을 습관적으로 써봐야겠다 -> 논리공부

int main() {
	int N, start, end;
	vector<pair<int, int>> meetings;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		meetings.push_back(make_pair(end, start)); // end기준으로 정렬할 것
	}

	sort(meetings.begin(), meetings.end());		// end기준 정렬

	int time = meetings[0].first;		// 첫번째는 무조건 넣기
	int count = 1;						// end기준으로 정렬되어 있으니 뒷 공간 많아짐
	for (int i = 1; i < N; i++)
	{
		if (meetings[i].second >= time) { // 시작시간이 그전 end시간보다 크다면 통과
			time = meetings[i].first;	  // end 기준으로 정렬되어 있으니 가장 작은크기 회의가 들어옴
			count++;					  // end 시간 업데이트, 회의수 업데이트
		}
	}
	cout << count;
}

// ref : https://cocoon1787.tistory.com/147