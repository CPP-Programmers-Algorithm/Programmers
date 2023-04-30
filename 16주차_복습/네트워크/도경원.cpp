
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& computers, int n) {
    if (!computers[n][n]) return false;//�湮�ߴٸ� Ż��
    computers[n][n] = 0; //��ȸǥ��
    for (int i = 0; i < computers.size(); i++) { //������ŭ �ݺ�, ����Ǿ��ٸ� ���
        if (computers[n][i]) dfs(computers, i);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {//��ȸ���� �ʾҴٸ� dfs Ž�� �� ans ����
        if (computers[i][i] && dfs(computers, i)) answer++;
    }
    return answer;
}