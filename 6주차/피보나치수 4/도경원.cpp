#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


string a, b, ans;
vector<int> va, vb;

string fiboBig(string &a, string &b) {					// 레퍼런스 타입으로 불러와 데이터를 복사하지 않는다
	string res = "";

	int diff_len = b.size() - a.size();				    // b가 뒤의 값으로 무조건 크니 차이는  b.s - a.s

	for (int i = 0; i < diff_len; i++)va.push_back(0);  // 자리를 만들어준다 // 뒷자리부터 idx 똑같이 쓰려고 넣음
	for (auto str : a)va.push_back(str - '0');			// int로 변환될 때 0을 빼줘야 
	for (auto str : b)vb.push_back(str - '0');			// 아스키가 아닌 원래의 수로 저장

	int carry = 0;
	for (int i = vb.size() - 1; i >= 0; i--) {			// 뒤에서 부터 더함
		int temp_sum = va[i] + vb[i];					// 이제 1자리 수의 덧셈이 됨

		if (carry == 1) {								// 전의 계산에 올림이 있다면
			temp_sum++;									// 계속 앞자리로 가는 다음 업데이트인 지금 올려줌
			carry = 0;									// 올림 초기화
		}
		if (temp_sum > 9) {								// 합이 9를 넘으면
			temp_sum %= 10;								// 10으로 나눈 나머지를 취하고
			carry = 1;									// 1을 올린다
		}												// 다음 차례에 올려줘야 해서 이 부분이 밑에 있음
		
		res += (temp_sum + '0');						// int에 '0'을 더해서 다시 string으로 바꿈 
	}
	if (carry == 1) res += '1';							// 모든 자리 수를 돌고도 올림이 남았다면 더해준다
	
	reverse(res.begin(), res.end());					// 뒷자리부터 계산해서 수가 거꾸로 되어 있으니 뒤집는다
	va.clear(); vb.clear();								// 사용한 벡터 초기화

	return res;
}
int main() {
	// n번째 피보나치 구하기
	int n; cin >> n;
	a = "0", b = "1";

	if (n == 0 || n == 1) cout << n;
	else {
		for (int i = 2; i <= n; i++) {
			ans = fiboBig(a, b);
			a = b;
			b = ans;									// 한 칸씩 뒤로 가며 피보나치 수를 계산한다
		}
		cout << b;
	}
	return 0;
}

//-----------------------------------
//         | 메모리    |  시간
//-----------------------------------
// python  |  35012   |  60
//-----------------------------------
// cpp     |  2024	  |  116


//ref : https://gdlovehush.tistory.com/504