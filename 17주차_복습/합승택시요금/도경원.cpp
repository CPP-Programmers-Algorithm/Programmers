// PRG_합승택시요금

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int d[201][201];

void FloydWarshall(const int n, const vector<vector<int>> w) {
    //초기화
    // 자기자신에 대한 연결 : 0
    // 그 외 연결         : INF
    // 간선정보업데이트
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for (int i = 0; i < w.size(); i++) {
        //cout << w[i][0];
        d[w[i][0]][w[i][1]] = w[i][2];
        d[w[i][1]][w[i][0]] = w[i][2];
    }
    //최단거리 업데이트
    // min(dij, dik + dkj)
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    // 모든 간선 간 최단거리 갱신
    FloydWarshall(n, fares);

    //임의의 중간점을 지날 때의 최소경로 구하기
    answer = d[s][a] + d[s][b];
    for (int k = 1; k <= n; k++) {
        if (d[s][k] != INF && d[k][a] != INF && d[k][b] != INF) {
            answer = min(answer, d[s][k] + d[k][a] + d[k][b]);
        }
    }

    return answer;
}


int main() {
    vector<vector<int>> fares{ {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25} };
    cout<<solution(6, 4, 6, 2, fares);
}

#pragma region note
// const쓸때 주의할점
//https://ladun.tistory.com/19#:~:text=%ED%95%A8%EC%88%98%EC%9D%98%20%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98%EC%97%90%20const%EB%A5%BC%20%EB%B6%99%EC%9D%B4%EB%A9%B4%20%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98%EC%9D%98%20%EA%B0%92%EC%9D%84%20%EB%B3%80%EA%B2%BD%ED%95%A0%20%EC%88%98,%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98%EC%97%90%20%EC%A0%81%EC%9A%A9%EC%8B%9C%ED%82%A4%EB%8A%94%20%EA%B2%83%EC%9D%B4%EB%8B%A4.%20%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98%EA%B0%80%20%EB%B3%80%EA%B2%BD%EB%90%98%EB%A9%B4%20%EC%95%88%EB%90%98%EB%8A%94%20%EA%B2%BD%EC%9A%B0%EC%97%90%20%EC%82%AC%EC%9A%A9%EB%90%9C%EB%8B%A4.
// segmentation fault (core dumped)
// define 뒤에 ;넣지 말기

//틀렸던 방법
/*
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    // 모든 간선 간 최단거리 갱신
    FloydWarshall(n, fares);

    // min(Dsa + Dsb , Dsa + Dab , Dsb + Dba)
    int dAlone = d[s][a] + d[s][b];
    int dSab   = d[s][a] + d[a][b];
    int dSba   = d[s][b] + d[b][a];

    answer = min(dAlone, min(dSab, dSba));

    return answer;
}
*/
#pragma endregion

