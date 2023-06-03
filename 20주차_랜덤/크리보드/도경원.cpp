#include <iostream>
#include <algorithm>
using namespace std;

// 크리보드

long long dp[101];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= 5; i++) {
        dp[i] = i;
    }
    for (int i = 6; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;                          // a를 그대로 출력하는 경우
        for (int j = 1; j < 4; j++) {                   // 복사해서 붙여넣기의 최대이득발생은 3번까지이다 -> 3번만 반복한다
            dp[i] = max(dp[i], dp[i - 2 - j] * (j + 1));// dp[복사된 순간의 값]*[몇배가 되는지], d[i-2]는 가장 짧게 복사해 줄 경우 복사되는 값, 그 후엔 j를 빼 더 전의 것을 복사하는 경우의수 계산
        }                                               // 즉, 현재의 값과 복사해서 왔을 때의 최대값을 비교해준다
    }                                                   
    cout << dp[N];
    return 0;
}
// dp[i]의 최대값
// 1. dp[i-1] + 1
// 2. dp[i-3]*2 -> 선태,복사 + 붙여넣기*1
// 3. dp[i-4]*3 -> 선택,복사 + 붙여넣기*2
// 4. dp[i-5]*4 -> 선택,복사 + 붙여넣기*3
// 네번 붙여넣으면 다시 복사 붙여넣기가 더 크다


//https://gamedoridori.tistory.com/104
//https://blog.naver.com/mym0404/222323009491