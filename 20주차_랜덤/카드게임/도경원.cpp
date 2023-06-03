#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 2000

//카드게임

// 틀려서 카피공부한 문제
// dp라고 생각되었는데 나는 2*max카드 수라고 테이블을 생각했음
// 구조를 생각하는 것 연습, dp의 경우의 수의 변수를 dp테이블의 가로세로 혹은 높이로 생각하기

int N;
int left_card[MAXN + 10];
int right_card[MAXN + 10];
int M[MAXN][MAXN];

void Input() { //카드정보 초기화
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> left_card[i];
	for (int i = 0; i < N; i++)
		cin >> right_card[i];
}
int DP(int left, int right) {
	if (left == N || right == N) return 0;

	if (M[left][right] != -1) return M[left][right]; // 이미 값이 있으면 그 값을 준다 -> 왜 이 경우의 수를 두번 이상 반복하지 않을까

	M[left][right] = 0;
	// 조건에 따라 반드시 오른쪽 카드 버리는 경우 -> 오른쪽 카드 만큼 얻음
	if (right_card[right] < left_card[left]) {
		M[left][right] += right_card[right] + DP(left, right + 1); // dp 매개변수에 idx를 증가시켜 전달한다
	}
	// 왼쪽을 버리는 경우와 둘다 버리는 경우 
	// 둘 중 큰 값을 가져온다
	else {
		M[left][right] += max(DP(left + 1, right), DP(left + 1, right + 1)); // 이 경우 문제 조건에 따라서 점수를 얻지 못하므로 인덱스만 이동시킨다
	}																		
	return M[left][right];
}
int main() {
	Input();

	memset(M, -1, sizeof(M));
	cout << DP(0, 0);;
	return 0;
}

// 문제의 논리
// 반드시 버려야 하는 경우를 if문으로 제하고
// 선택할 수 있는 경우의 수를 dp와 max의 조합으로 찾는다

// 헷갈릴 수 있는 지점
// 처음 dp 루프에 들어갈 때 근시적으로 값을 비교하는 것 같으니 dp가 내부에서 다 돌고 돌려주는 최종의 값을 비교하기 때문데 논리가 성립한다

// 의문점
// 뒤쪽에 무지막지하게 큰 수가 나오면 어떻하지? 모든 경우의 수를 dx로도는 것도 아닌데