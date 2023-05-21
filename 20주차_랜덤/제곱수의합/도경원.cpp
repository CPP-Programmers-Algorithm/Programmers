#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
//틀린문제 :예시는 통과했으나 반례를 찾지 못함
int main() {
    int n;
    int m = 2;
    int dp[100001];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        dp[i] = i;

    for (int i = 4; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);// 이전에 줄여놓았던 최소항의 갯수를 다시 가져와서 사용 // + 1을 해주는 것은 j*j가 하나의 항이기 때문에
        }
    }

    printf("%d\n", dp[n]);
}






//https://velog.io/@chowisely/BOJ-1699