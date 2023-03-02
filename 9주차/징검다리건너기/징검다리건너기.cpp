#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> stones;

int solution(vector<int> stones, int k) 
{
	int start = 1, end = 200000000, answer;
	vector<int> stones_copy;
	while (end >= start)
	{
		int mid = start + (end - start) / 2;
		stones_copy = stones;

		// 연속으로 0이 나올 때 count를 1씩 증가시키고, 연속성이 깨지면 다시 count를 0으로 초기화
		int count = 0;
		for (int i = 0; i < stones_copy.size(); i++)
		{
			if (stones_copy[i] - mid <= 0)
				count++;
			else
				count = 0;

			// 연속으로 나온 0의 개수가 가능한 거리를 넘으면 바로 반복 종료
			if (count >= k)
				break;
		}
		if (count >= k)			// 건너는 인원을 너무 많이 잡아 건널 수 있는 거리 초과 ->  mid 이상은 불가능하므로 mid 미만 값 탐색
			end = mid - 1;
		else                    // 건너는 인원을 너무 적게 잡거나 딱 맞게 잡아 거리 안에 가능 -> 일단 answer를 mid로 초기화하고 mid 초과 값도 탐색  
		{
			answer = mid;
			start = mid + 1;
		}
	}
	return answer + 1;		// mid가 n이면 n번째 인원을 통과하고도 한 명 더 통과할 수 있는 상태이므로 +1
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	cout << solution(stones, 3);
}