#include <iostream>
using namespace std;

int dp[10];

int main(void) {
    int n;
    cin >> n;

    dp[2] = 2;                      // 자리수가 1일 때 나머지가 0인 수가 없으므로 하나를 빼줘야 함
    for (int i = 3; i < 10; i++){
        dp[i] = dp[i - 1] * 3;       // 경우의 수가 반복된다
    }

    cout << dp[n] << '\n';
}





//https://velog.io/@qwerty1434/%EB%B0%B1%EC%A4%80-14650%EB%B2%88-%EA%B1%B7%EB%8B%A4%EB%B3%B4%EB%8B%88-%EC%8B%A0%EC%B2%9C%EC%97%AD-%EC%82%BC-Small