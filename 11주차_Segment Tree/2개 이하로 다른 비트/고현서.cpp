#include <string>
#include <vector>
#include<math.h>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (int i = 0; i < numbers.size(); i++) {
		long long num = numbers[i];
		long long ans = 0;
		int idx = 0;
		bool isCheck = false;
		while (num) {
			if (!(num % 2) && !isCheck) {
				isCheck = true;
				ans += pow(2, idx);
				for (int j = idx - 2; j >= 0; j--)
					ans += pow(2, j);
			}
			else if (isCheck) {
				ans += (num % 2) * pow(2, idx);
			}
			num /= 2;
			idx++;
		}
		// 111인 경우
		if (!isCheck) {
			ans += pow(2, idx);
			for (int j = idx - 2; j >= 0; j--)
				ans += pow(2, j);
		}
		answer.push_back(ans);
	}
	return answer;
}

/*
vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (int i = 0; i < numbers.size(); i++) {
		long long num = numbers[i];
		long long ans = 0;
		int idx = 0;
		bool isCheck = false;
		while (num) {
			if (!(num & 1) && !isCheck) {
				isCheck = true;
				ans |= (1 << idx);
				ans &= ~(1 << idx-1);
				for (int j = idx - 2; j >= 0; j--)
					ans |= (1 << j);
			}
			else {
				ans |= ((num & 1) ?
					(static_cast<long long>(1) << (idx)) :
					0);
			}
			num >>= 1;
			idx++;
		}
		// 111인 경우
		if (!isCheck) {
			ans = 0;
			//10000
			ans |= (1 << (idx + 1));
			//01111
			ans -= 1;
			//01011
			ans &= ~(1 << (idx - 1));
		}
		answer.push_back(ans);
	}
	return answer;
}
*/
