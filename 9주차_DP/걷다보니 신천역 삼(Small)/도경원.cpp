#include <iostream>
using namespace std;

int dp[10];

int main(void) {
    int n;
    cin >> n;

    dp[2] = 2;                      // �ڸ����� 1�� �� �������� 0�� ���� �����Ƿ� �ϳ��� ����� ��
    for (int i = 3; i < 10; i++){
        dp[i] = dp[i - 1] * 3;       // ����� ���� �ݺ��ȴ�
    }

    cout << dp[n] << '\n';
}





//https://velog.io/@qwerty1434/%EB%B0%B1%EC%A4%80-14650%EB%B2%88-%EA%B1%B7%EB%8B%A4%EB%B3%B4%EB%8B%88-%EC%8B%A0%EC%B2%9C%EC%97%AD-%EC%82%BC-Small