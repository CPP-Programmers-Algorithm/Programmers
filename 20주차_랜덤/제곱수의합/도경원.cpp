#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

//제곱수의합
//틀린문제 :예시는 통과했으나 반례를 찾지 못함

int main() {
    int n;
    int m = 2;
    int dp[100001];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        dp[i] = i;

    for (int i = 4; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {        // j * j<=i 가 의미하는 것 : 빼줄 제곱수가 아직 존재한다
            dp[i] = min(dp[i], dp[i - j * j] + 1);// 이전에 줄여놓았던 최소항의 갯수를 다시 가져와서 사용 // + 1을 해주는 것은 j*j가 하나의 항이기 때문에
        }   
    }

    printf("%d\n", dp[n]);
}


// dp[4], dp[4-4]+1
// dp[5], dp[5-4]+1





//https://velog.io/@chowisely/BOJ-1699