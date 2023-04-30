#include <iostream>
using namespace std;

int graph[105][105];
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) //그래프초기화
		for (int j = 0; j < N; j++)cin >> graph[i][j];

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) //i -> j -> k 로 가는 경로가 있는지 확인한다
				if (graph[i][k] && graph[k][j]) graph[i][j] = 1; //즉 루프를 돌면서 새로운 선들을 추가해주는 과정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << graph[i][j] << " ";
		cout << "\n";
	}
}