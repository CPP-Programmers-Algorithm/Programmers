#include <iostream>
#include <vector>
#define INF 987654321;
using namespace std;

int town[51][51];
int dst[51][51];
// n = 마을의 갯수
// k = 배달가능 시간
// vector = 간선정보
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

	// dst에 최고값 저장
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			dst[i][j] = INF;
			town[i][j] = INF;
		}
	}


	// 간선저장
	for (int i = 0; i < road.size(); i++) //초기화
	{

		int s, e, len;
		s   = road[i][0];
		e   = road[i][1];
		len = road[i][2];
		town[s][e] = len;
		town[e][s] = len;
		dst[s][e] = len;
		dst[s][e] = len;
	}

	for (int k = 0; k < N; K++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (town[i][j] > town[i][k] + town[k][j]) {
					town[i][j] = town[i][k] + town[k][j];
					dst[i][j]  = town[i][k] + town[k][j];
				}
			}
		}
	}
	
	for (int j = 0; j < N; j++)
	{
		if (dst[0][j] <= K)answer++;
	}

    return answer;
}