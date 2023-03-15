#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h> 
using namespace std;

// 세그먼트 트리 배열
static vector<long> tree;
long getSum(int s, int e);
void changeVal(int index, long val);
void setTree(int i);

int main()
{
	// N의 개수
	// M(변경이 일어나는 개수)
	// K(구간 합을 구하는 개수)
	int N, M, K;
	cin >> N >> M >> K;
	int treeHeight = 0;
	int Length = N;

	// 만약 개수가 5라면 0이 아닐때까지 높이++ 
	// 높이는 3
	while (Length != 0) {
		Length /= 2;
		treeHeight++;
	}
	// treeSize = 16;

	int treeSize = int(pow(2, treeHeight + 1));
	// 4^2 16
	int leftNodeStarIndex = treeSize / 2;
	// [7]
	tree.resize(treeSize + 1);
	// 벡터 초기화
	
	// 데이터를 래프트 노드에 입력받기
	// {1,2,3,4,5}
	for (int i = leftNodeStarIndex; i < leftNodeStarIndex + N; i++) {
		cin >> tree[i];
	}
	 
	setTree(treeSize - 1);

	for (int i = 0; i < M + K; i++) {
		long a, s, e;
		cin >> a >> s >> e;
		// 변경
		if (a == 1) {
			// 3 + 8  - 1 
			// 10번 인덱스
			changeVal(leftNodeStarIndex -1 + s, e);
		}
		// 구간 합
		else if (a == 2)
		{
			s = s + leftNodeStarIndex -1;
			e = e + leftNodeStarIndex -1;

			cout << getSum(s, e) << "\n";
		}
	}
}

// 부모 노드 찾아가면서 변경된 수만큼 더해준다.
void changeVal(int index, long val) {
	long diff = val - tree[index];
	while (index > 0) {
		tree[index] = tree[index] + diff;
		index = index / 2;
	}
}


// 구간 합 연산 함수
long getSum(int s, int e) {
	long partSum = 0;
	// 만약 s 가 e보다 작다면
	while (s <= e) {
		if (s % 2 == 1) {
			partSum = partSum + tree[s];
		}
		if (e % 2 == 0) {
			partSum = partSum + tree[e];
		}
		// start_index depth 변경: s = (s + 1) / 2
		// end_index depth 변경: e = (e - 1) / 2
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}		
	return partSum;  
}
// 트리에 빈값 채워준다
void setTree(int i)
{
	while (i != 1) {
		tree[i / 2] += tree[i];
		i--;
	}
}


