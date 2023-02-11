#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

int Distance(int from, int to) {
	if (to - from <= 0)
		return 0;
	else
		return to - from - 1;
}
int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	vector<int> dists;
	dists.push_back(Distance(0, stations[0] - w));
	dists.push_back(Distance(stations[stations.size() - 1] + w, n + 1));
	for (int i = 0; i < stations.size() - 1; i++) {
		dists.push_back(Distance(stations[i] + w, stations[i + 1] - w));
	}
	int length = w * 2 + 1;
	for (int i = 0; i < dists.size(); i++) {
		answer += (ceil)(dists[i] / (double)length);
	}
	return answer;
}