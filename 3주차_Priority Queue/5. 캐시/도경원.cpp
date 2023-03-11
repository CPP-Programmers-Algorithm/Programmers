#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <deque>

using namespace std;

// deque는 vector의 단점을 보완하기 위한 배열기반구조
// vector : 새로운 원소추가될 때 메모리 재할당 후 이전원소복사
// deque  : 여러개의 메모리블록을 할당하고 하나의 불록처럼 여김
// 메모리부족 시 일정한 크기의 새로운 메모리블록 할당


int solution(int cacheSize, vector<string> cities) {

	int answer = 0;
	
	deque<string>cache; // LRU 알고리즘을 deque로 구현 // 앞 뒤 삽입삭제 쉬움
						// 앞의 것이 가장 옛날, 맨 뒤가 최신
						
	for (size_t i = 0; i < cities.size(); i++)
	{
		string city = cities[i];

		for (size_t j = 0; j < city.length(); j++)
		{
			city[j] = tolower(city[j]);  // city 이름을 소문자로 바꾸어준다
										 // 대소문자만 다르고 문자가 똑같은 도시 있음
		}

		bool hit = false;
		int idx = 0;
		for (idx = 0; idx < cache.size(); idx++) {
			if (cache[idx] == city) {    // 현재 읽어드린 city가 cache에 있는지 검사
				hit = true;
				break;
			}
		}

		cache.push_back(city);			 //읽어드린 city를 맨뒤에 넣는다
		
		if (hit) { // 캐시가 hit일때
			cache.erase(cache.begin() + idx);  // .begin()은 deque의 첫번째 요소를 가리킴
			answer += 1;					   // .begin()은 iterator를 반환한다 -> 포인터와 비슷// 컨테이너에 저장된 원소 참조시 사용
		}
		else { // 캐시가 miss일때
			if (cache.size() > cacheSize) { // cache가 넘쳤을 때, 맨 앞에 있는 가장 오래된 데이터 삭제
				cache.pop_front();
			}
			answer += 5;
		}
	}
	return answer;
}




// 위 문제는 잘 몰라서 다른 분의 코드를 카피하며 공부했습니다
// ref : https://blockdmask.tistory.com/73
// ref : https://algosu.tistory.com/m/80
// ref : https://learn.microsoft.com/ko-kr/cpp/standard-library/deque-class?view=msvc-170
// Key concept : deque, iterator
// 
// 궁금한 점 : 앞과 뒤에 삽입할 때 더이상 공간이 없으면 주소가 증감하지 않을까?