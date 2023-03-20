#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h> 
using namespace std;

// 트리를 위한 배열
vector<long> maxTree;
vector<long> minTree;

// 트리에 입력을 받는다
// 2^k > 10;
// k = 4
// 트리 배열 크기 2^4 * 2 
int N, M;
long getMin(int s, int e);
long getMax(int s, int e);
void setMinTree(int i);
void setMaxTree(int i);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int k = 0;
	while (pow(2, k) <= N)
	{
		k++;
	}
	long treeSize = pow(2, k) * 2;
	long leftNodeStart = treeSize / 2;
	minTree.resize(treeSize + 1);
	maxTree.resize(treeSize + 1);
	fill(minTree.begin(), minTree.end(), LONG_MAX);
	fill(maxTree.begin(), maxTree.end(), 0);
	// 트리에 넣자
	for (int i = leftNodeStart; i < leftNodeStart+ N; i++)
	{
		long a;
		cin >> a;
		minTree[i] = a;
		maxTree[i] = a;
	}

	setMinTree(treeSize - 1);
	setMaxTree(treeSize - 1);

	// 최솟값 최댓값을 구하자
	for (int i = 0; i < M; i++)
	{
		// 입력을 받고 
		// 최솟값 최댓값 구하는 함수실행
		long s, e;
		cin >> s >> e;
		s = s + leftNodeStart - 1;
		e = e + leftNodeStart - 1;
		cout << getMin(s, e) << " " << getMax(s, e) << "\n";
		
	}
}

long getMin(int s, int e)
{
	long Min = LONG_MAX;

	while (s <= e)
	{
		if (s % 2 == 1) {
			Min = min(Min, minTree[s]);
		}
		if (e % 2 == 0) {
			Min = min(Min, minTree[e]);
		}
	// 선택되었다는건 독립되었다는것
	// 독립되었다는건 처음일경우 +1로 넘어가야한다.
	// 마지막은 반대
	s = (s + 1) / 2;
	e = (e - 1) / 2;
	}

	return Min;
}


long getMax(int s, int e)
{
	long Max = 0;

	while (s <= e)
	{
		if (s % 2 == 1) {
			Max = max(Max, maxTree[s]);
		}
		if (e % 2 == 0) {
			Max = max(Max, maxTree[e]);
		}
	s = (s + 1) / 2;
	e = (e - 1) / 2;
	}


	return Max;
}

void setMinTree(int i)
{

	// treeSize-1 가 1이 아니라면
	// 1이되면 비어있어야할 0이 채워짐
	// 최솟값으로 교체
	while (i != 1)
	{
		if (minTree[i / 2] > minTree[i])
		{
			minTree[i / 2] = minTree[i];
		}
		i--;
	}
}

void setMaxTree(int i)
{
	while (i != 1)
	{
		if (maxTree[i / 2] < maxTree[i])
		{
			maxTree[i / 2] = maxTree[i];
		}
		i--;
	}
}


