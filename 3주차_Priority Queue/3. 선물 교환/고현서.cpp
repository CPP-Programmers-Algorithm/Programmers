#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include <queue>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
}

//참여하는 학생 벡터
vector<int> ans;
int visited[200001];
//준 정보
vector<vector<int>> sendInfo;
//받은 정보
vector<vector<int>> receiveInfo;
int n;
void Check() {
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (receiveInfo[i].size() < 2) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int qFront = que.front();
		que.pop();
		if (visited[qFront]) continue;
		visited[qFront] = true;
		//1. 내가 선물을 준 친구들의 리스트에서 내 이름을 뺀다.
		for (int i = 0; i < sendInfo[qFront].size(); i++) {
			int presentTo = sendInfo[qFront][i];
			receiveInfo[presentTo].erase(
				remove(receiveInfo[presentTo].begin(),
					receiveInfo[presentTo].end(), qFront),
				receiveInfo[presentTo].end());
			//만약에 이 친구가 내가 없으면 2보다 작아진다? 당장 큐에 넣어
			if (receiveInfo[presentTo].size() < 2)
				que.push(presentTo);

		}
		//2. 나에게 선물을 준 친구를 제거해야한다.
		for (int i = 0; i < receiveInfo[qFront].size(); i++) {
			que.push(receiveInfo[qFront][i]);
		}
		//해당 친구는 희망이 없으니 지워준다.
		ans.push_back(qFront);
	}
}

int main() {
	init();
	cin >> n;
	for (int i = 0; i <= n; i++) {
		sendInfo.push_back(vector<int>());
		receiveInfo.push_back(vector<int>());
	}
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		sendInfo[i].push_back(x);
		sendInfo[i].push_back(y);

		receiveInfo[x].push_back(i);
		receiveInfo[y].push_back(i);

	}
	Check();
	cout << (n - (int)ans.size()) << "\n";
	for (int i = 1; i <= n; i++) {
		if (!visited[i])cout << i << " ";
	}

}