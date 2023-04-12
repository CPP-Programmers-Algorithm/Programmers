#include <iostream>
#include <vector>
#include <algorithm> 
#define MAX 9
using namespace std;

int N, M;
int arr[MAX];
vector<int> num;
// vector을 고른이유 sort로 정열해야되니깐
bool visited[MAX];
// v는 자리 위치(?)
// v 가 0이면 arr[0] 
// v 가 1이면 arr[1]
// v 가 2이면 출력
// arr[0] , arr[1]이 출력되니 주어진 수가 만약 9,8,7,1 이면
// 1 7 이 출력
void dfs(int v)
{
    if (v == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    // v== 0일때
    // 숫자 갯수만큼 사용했는지 체크
    // 맨처음 i 가 1일때 
    // visited[1] 이 true가 되고
    // arr[0] = num[0](1)
    // dfs(v(0) + 1)
    // dfs(1);
    // v == 1일때 
    // 다시 N만큼 
    // 하지만 visited[1]은 방문 체크되었어 PASS
    // 같은 숫자 못함..
    // i = 2일때
    // visited[2] = true
    // arr[1] = num[1](7)
    // dfs(2)
    // v==m 이므로 1 7 출력
    // return 
    // visited[2] = false;
    // v== 1이고 i == 2일때 재귀에서 돌아왔으므로
    // i == 3 시작
    // 똑같이 arr[0]. arr[1] 출력
    // i == 4 마찬가지
    // 다끝나면 
    // v == 0 일떄 i = 1일때 들어간 재귀가 다끝난거니
    // v == 0 i = 2일때 다시 시작
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                arr[v] = num[i-1];
                dfs(v + 1);
                visited[i] = false;
            }
        }
    
}

int main()
{
    // dfs(1)이면 안되는 이유 M이 1이면 바로끝남
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }
    // 작은수 부터 뽑아야 하니 정렬 해준다.
    sort(num.begin(), num.end());
    dfs(0);
}
