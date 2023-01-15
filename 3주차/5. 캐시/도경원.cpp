#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <deque>

using namespace std;

// deque�� vector�� ������ �����ϱ� ���� �迭��ݱ���
// vector : ���ο� �����߰��� �� �޸� ���Ҵ� �� �������Һ���
// deque  : �������� �޸𸮺���� �Ҵ��ϰ� �ϳ��� �ҷ�ó�� ����
// �޸𸮺��� �� ������ ũ���� ���ο� �޸𸮺�� �Ҵ�


int solution(int cacheSize, vector<string> cities) {

	int answer = 0;
	
	deque<string>cache; // LRU �˰����� deque�� ���� // �� �� ���Ի��� ����
						// ���� ���� ���� ����, �� �ڰ� �ֽ�
						
	for (size_t i = 0; i < cities.size(); i++)
	{
		string city = cities[i];

		for (size_t j = 0; j < city.length(); j++)
		{
			city[j] = tolower(city[j]);  // city �̸��� �ҹ��ڷ� �ٲپ��ش�
										 // ��ҹ��ڸ� �ٸ��� ���ڰ� �Ȱ��� ���� ����
		}

		bool hit = false;
		int idx = 0;
		for (idx = 0; idx < cache.size(); idx++) {
			if (cache[idx] == city) {    // ���� �о�帰 city�� cache�� �ִ��� �˻�
				hit = true;
				break;
			}
		}

		cache.push_back(city);			 //�о�帰 city�� �ǵڿ� �ִ´�
		
		if (hit) { // ĳ�ð� hit�϶�
			cache.erase(cache.begin() + idx);  // .begin()�� deque�� ù��° ��Ҹ� ����Ŵ
			answer += 1;					   // .begin()�� iterator�� ��ȯ�Ѵ� -> �����Ϳ� ���// �����̳ʿ� ����� ���� ������ ���
		}
		else { // ĳ�ð� miss�϶�
			if (cache.size() > cacheSize) { // cache�� ������ ��, �� �տ� �ִ� ���� ������ ������ ����
				cache.pop_front();
			}
			answer += 5;
		}
	}
	return answer;
}




// �� ������ �� ���� �ٸ� ���� �ڵ带 ī���ϸ� �����߽��ϴ�
// ref : https://blockdmask.tistory.com/73
// ref : https://algosu.tistory.com/m/80
// ref : https://learn.microsoft.com/ko-kr/cpp/standard-library/deque-class?view=msvc-170
// Key concept : deque, iterator
// 
// �ñ��� �� : �հ� �ڿ� ������ �� ���̻� ������ ������ �ּҰ� �������� ������?