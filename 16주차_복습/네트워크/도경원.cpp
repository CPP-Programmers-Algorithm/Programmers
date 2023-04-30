
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& computers, int n) {
    if (!computers[n][n]) return false;//방문했다면 탈출
    computers[n][n] = 0; //순회표시
    for (int i = 0; i < computers.size(); i++) { //노드수만큼 반복, 연결되었다면 재귀
        if (computers[n][i]) dfs(computers, i);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {//순회하지 않았다면 dfs 탐색 후 ans 증가
        if (computers[i][i] && dfs(computers, i)) answer++;
    }
    return answer;
}