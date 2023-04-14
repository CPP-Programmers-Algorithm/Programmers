#include <iostream>
#include <string>
#include <cmath>
#define MAX 9
using namespace std;

int arr[MAX];
int N;
bool p = true;
string num;
int n;

// 소수인지 아닌지 아렬주는 함수
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        // 나눠지니깐 소수 아님
        if (n % i == 0) {
            return false;
        }
    }
    // 소수입니다.
    return true;
}

void DFS(int v) {
    if (v == N) {
        // num 초기화
        num = "";
        for (int i = 0; i < N; i++) {
            // 숫자 붙이려고 string으로 바꾸고
            num += to_string(arr[i]);
        }
        // 다시 숫자로
        n = stoi(num);
        cout << n << "\n";
        return;
    }

    for (int i = 1; i <= 9; i++) {
        arr[v] = i;
        num = "";
        // p는 소수인지 아닌지 nool
        p = true;
        for (int j = 0; j <= v; j++) {
            num += to_string(arr[j]);
            n = stoi(num);
            if (!isPrime(n)) {
                p = false;
                break;
            }
        }
        // 소수면 depth증가
        if (p) {
            DFS(v + 1);
        }
    }
}

int main() {
    cin >> N;
    DFS(0);
}
