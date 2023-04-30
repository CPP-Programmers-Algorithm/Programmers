#include <iostream>
#include <vector>

#define pii pair<int,int>
#define x first
#define y second

using namespace std;

vector<pii> dir = { {-1,-1}, {0,1}, {1,0} };
int map[1001][1001];

vector<int> solution(int n) {

	vector<int> answer;
	if (n == 1) { answer = { 1     }; return answer; }
	if (n == 2) { answer = { 1,2,3 }; return answer; }

	int num = 2 * n;
	int h = n-2;
	int v = n-2;
	int i = 0; //방향인덱스
	


	for (int i = 0; i < n; i++) { //세로가로 초기화
		map[i][0] = i + 1;
		map[n-1][i] = n + i;
	}

	while (true) {
		
		map[v][h] = num++;
		
		if (map[v + dir[i].y][h + dir[i].x] != 0) {
			if (i == 2)i = 0; else i++;
			if (map[v + dir[i].y][h + dir[i].x] != 0)break; //순환한 곳에도 0이 있다면
		}
		h += dir[i].x;
		v += dir[i].y;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (map[i][j] == 0)break;
			answer.push_back(map[i][j]);
		}
	}
	return answer;
}
int main() {
	int n; cin >> n;
	solution(n);

}

