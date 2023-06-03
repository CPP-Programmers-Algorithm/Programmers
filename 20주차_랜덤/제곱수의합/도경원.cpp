#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

//����������
//Ʋ������ :���ô� ��������� �ݷʸ� ã�� ����

int main() {
    int n;
    int m = 2;
    int dp[100001];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        dp[i] = i;

    for (int i = 4; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {        // j * j<=i �� �ǹ��ϴ� �� : ���� �������� ���� �����Ѵ�
            dp[i] = min(dp[i], dp[i - j * j] + 1);// ������ �ٿ����Ҵ� �ּ����� ������ �ٽ� �����ͼ� ��� // + 1�� ���ִ� ���� j*j�� �ϳ��� ���̱� ������
        }   
    }

    printf("%d\n", dp[n]);
}


// dp[4], dp[4-4]+1
// dp[5], dp[5-4]+1





//https://velog.io/@chowisely/BOJ-1699