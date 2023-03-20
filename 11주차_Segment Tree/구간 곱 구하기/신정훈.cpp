#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 세그먼트 트리 배열
vector<long long> tree;
int MOD = 1'000'000'007;
long long getMultiple(int s, int e);
void changeVal(int index, long val);
void setTree(int i);

int main()
{
    // N의 개수
    // M(변경이 일어나는 개수)
    // K(구간 합을 구하는 개수)
    int N, M, K;
    cin >> N >> M >> K;
    // 트리 높이
    int treeHeight = 0;
    int length = N;
    while (length != 0)
    {
        length /= 2;
        treeHeight++;
    }

    int treeSize = int(pow(2, treeHeight + 1));
    int leftNodeStartIndex = treeSize / 2 -1;
   
    tree.resize(treeSize + 1);
    fill(tree.begin(), tree.end(), 1);
    for (int i = leftNodeStartIndex+1; i <= leftNodeStartIndex + N; i++)
    {
        cin >> tree[i];
    }
    setTree(treeSize - 1);
    // 1일때 변경
    // 2일때 곱
    for (int i = 0; i < M + K; i++)
    {
        long long a, s, e;
        cin >> a >> s >> e;
        if (a == 1)
        {
            changeVal(leftNodeStartIndex + s, e);
        }
        else if (a == 2)
        {
            s = s + leftNodeStartIndex;
            e = e + leftNodeStartIndex;
            cout <<getMultiple(s, e) << "\n";
        }
    }
}

long long getMultiple(int s, int e)
{
    long long partMul = 1;

    while (s <= e) {
        if (s % 2 == 1) {
            partMul = partMul * tree[s] % MOD;
            s++;
        }
        if (e % 2 == 0) {
            partMul = partMul * tree[e] % MOD;
            e--;
        }
        s = s / 2;
        e = e / 2;
    }
    return partMul;
}

void changeVal(int index, long val)
{
    tree[index] = val;
    while (index > 1) {
        index = index / 2;
        tree[index] = tree[index * 2]%MOD * tree[index *2 + 1] % MOD;        
    }
}
void setTree(int i)
{
    while (i != 1) {
        tree[i / 2] = tree[i/2] * tree[i] % MOD;
        i--;
    }
}
