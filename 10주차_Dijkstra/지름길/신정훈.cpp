#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
// V는 지름길 개수 
// M은 최대거리
int V, M;
int a =0;
int b;
int c;
vector<int> mdistance;
vector<edge> mlist[10001];
priority_queue<edge, vector<edge>, greater<edge>> q;

int main()
{
	cin >> V >> M;
	mdistance.resize(10001);
	fill(mdistance.begin(), mdistance.end(), INT_MAX);

	for (int i = 0; i < V; i++) {
		// u는 시작
		// v는 지름길 도착
		// w는 가중치
		int u, v, w;
		cin >> u >> v >> w;
		if (v > M)
		{
			continue;
		}
		mlist[u].push_back({ v, w });
	}

	mdistance.push_back(0);
	mdistance[0] = 0;
		for (int i = 0; i < M+1; i++)
		{
				// mdistance[i]무한대라면
				if (mdistance[i] > M && i != 0)
				{
					// 전에거 +1
				mdistance[i] = mdistance[i-1] + 1;
					
				//mdistance[i]= min(mdistance[i], (mdistance[b] + i - mdistance[b]));
				}
				// 0이 아니라면 업데이트가 되었다면 midisance[50] = 10 
				else if (mdistance[i] != 0)
				{
					// 전에거랑 최솟값 비교
			mdistance[i] = min(mdistance[i-1]+1, mdistance[i]);

				}
			for (int j = 0; j < mlist[i].size(); j++)
			{
				edge tmp = mlist[i][j];
				b = tmp.first;
				c = tmp.second;
				if (mdistance[b] > mdistance[i] + c)
				{
					// mdistance[next] = next까지 가는 비용
					mdistance[b] = c + mdistance[i];
				}
			}
		}
	cout << mdistance[M] << "\n";
}

