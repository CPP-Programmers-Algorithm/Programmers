#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <sstream>
#include <string>

using namespace std;
typedef pair<int, int> pii;		// (회의 시작 시각, 끝나는 시각) 저장

bool Compare(pii confA, pii confB)
{
	if (confA.first == confB.first)
		return confA.second < confB.second;
	else
		return confA.first < confB.first;
}

int solution(vector<pii> confs)
{
	int count = 0;
	int start = 0, end = 0;
	for (int i = 0; i < confs.size(); i++)
	{
		if (confs[i].first < end)		// (이번 순서 회의의 시작 시각 < 이전에 저장된 회의의 종료 시각)일 때  
		{
			if (confs[i].second <= end)	// (이번 순서 회의의 종료 시각 <= 이전에 저장된 회의의 종료 시각)이면
			{
				start = confs[i].first;	// 이전 회의를 취소하고 이번 순서 회의를 넣어 가장 최근 회의로 갱신
				end = confs[i].second;
			}
		}
		else if (confs[i].first >= end)	// (이번 순서 회의 시작 시각 >= 이전에 저장된 회의의 종료 시각)일 때
		{								
			count++;					// 겹치는 시간 없으므로 가능한 회의 -> count 1 증가
			start = confs[i].first;		// 이번 순서 회의를 가장 최근 회의로 갱신
			end = confs[i].second;
		}
	}
	return count;
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;

	vector<pii> conferences;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		conferences.push_back(pii(start, end));
	}

	sort(conferences.begin(), conferences.end(), Compare);	// 회의 시작 시각 오름차순으로 정렬, 시작 시간이 같은 케이스는 종료 시각 오름차순으로 정렬
	cout << solution(conferences);
}