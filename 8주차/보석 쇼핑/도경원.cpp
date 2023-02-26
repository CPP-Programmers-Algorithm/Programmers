#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	int gems_size = gems.size();
	int min_dist = 100001;

	unordered_map<string, int> list;		//보석의 종류, 보석의 갯수
	unordered_set<string> s_temp;			//영역 내 포함된 보석 종류계산

	for (int i = 0; i < gems_size; i++) { // 보선의 종류를 구하기 위한 부분
		s_temp.insert(gems[i]);
	}
	int kind = s_temp.size(); 
	int idx_r = 0, idx_l = 0;

	while (true) {
		if (list.size() >= kind)		 // 모두 담고 나서는 영역을 이동해야 한다
		{
			list[gems[idx_l]]--;		 // 해당 key에 있는 value값을 하나 줄인다

			if (list[gems[idx_l]] == 0)  // 0이라면 해당보석을 하나만 가지고 있었던 것
			{
				list.erase(gems[idx_l]); // l의 포인터를 옮길 것이어서 지워준다 - 왼쪽은 지우는 역활만 하면 된다
			}
			idx_l++;					 // 왼쪽 포인터 증가
		}
		else if (idx_r == gems_size) {	 // 오른쪽 포인터가 끝에 도달했으면 종료한다
			break;
		}
		else {							 // < 여기가 처음 들어오는 곳 >
			list[gems[idx_r]]++;		 // list의 사이즈가 kind와 같아질 때까지 넣어줌 - 맵이라 중복허용x
			idx_r++;					 // 오른쪽 포인터를 증가
		}

		if (list.size() == kind) {		 // 필요한 보석이 모두 들어왔다는 뜻
			int temp = idx_r - idx_l;	 // 영역을 구한다
			if (temp < min_dist) {		 // 현재 구한 영역이 이전 영역보다 작다면
				answer.clear();					// answer을 갱신해준다
				answer.push_back(idx_l + 1);
				answer.push_back(idx_r);
				min_dist = temp;				// 최소길이를 갱신해준다
			}
		}
	}
	return answer;
}







//https://blog.naver.com/kks227/220795165570
//https://novemberfirst.tistory.com/54