#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

typedef long long ll;

using namespace std;

ll arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, M; // N : 레슨수, M : 블루레이의 갯수
	cin >> N >> M;

	ll sum = 0, low = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i]; // 모든 레슨의 길이를 더하 것은 high가 되고
		low = max(low, arr[i]); // 각 레슨 중 가장 긴 것은 low가 된다
	}

	ll high = sum;

	while (low <= high) {
		ll cnt = 0, tempSum = 0; // cnt : 계산되는 블루레이의 수 // tempSum : 각 블루레이에 들어가는 영상길이의 합
		ll mid = (low + high) / 2;

		for (int i = 0; i < N; i++) // 반복문을 써서 계산이 많을 것 같지만 시간복잡도는 aN이다
		{
			if (tempSum + arr[i] > mid) { // 현재 레이블에 생각한 최소값을 넘어가면 다음 레이블에 저장하는 식
				tempSum = 0;
				cnt += 1;
			}
			tempSum += arr[i]; // 레이블에 영상저장
		}
		if (tempSum != 0) cnt += 1; // 블루레이의 크기가 가정한 크기보다 작아서 1 증가 못시키면 1더함

		if (cnt <= M) { // 생성되는 레이블 갯수가 모자르다면 high 값줄임
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << low;
	return 0;
}
//ref : https://chanhuiseok.github.io/posts/baek-22/