#include<iostream>
#include<algorithm>
using namespace std;

int map[1001][1001];
struct BigSquare {
	int width = 0;
	int height = 0;
};

void UpdateMap(int& w, int& h);
void FindBigSquare(int& w, int& h, BigSquare square);


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	UpdateMap(n, m);
	
	BigSquare bigSquare;
	FindBigSquare(n, m, bigSquare);

	cout << bigSquare.width;
}

void UpdateMap(int& w, int& h) {
	for (int i = 0; i < h; i++){
		string tmp; cin >> tmp;

		for (int j = 0; j < w; j++){
			map[i][j] = (int)tmp[j] - 48;
		}
	}
}

void FindBigSquare(int& w, int& h, BigSquare square) {
	// ���� ���������� ��ȸ
	// Move anchor
	// 1. 1*1 �˻� -> 0�� ���ٸ� ����Ȯ��
	// 2. 2*2 �˻� -> 0�� ���ٸ� ����Ȯ��
	// 0�� �ִٸ� Move anchor

	pair<int, int> curPos;
	
	int maxSqWidth = 0;

	//��Ŀ��ȯ
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			int sqWidth = 0;
			// ���簢�� ��ȯ
			for (int sqi = i; sqi <= sqWidth; sqi++){
				for (int sqj = j; sqj <= sqWidth; sqj++){
					if (sqi > h || sqj > w) break;// �����˻�
					if (!map[sqi][sqj]) break;	  // 01�˻�
					sqWidth++;
				}
			}
			maxSqWidth = max(maxSqWidth, sqWidth);
		}
	}
	square.width = maxSqWidth;
	square.height = maxSqWidth;
}


