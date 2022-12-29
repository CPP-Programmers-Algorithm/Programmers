#include<iostream>
#include<vector>

using namespace std;

//�湮 ó���� ��������
bool isVisited[102];

void DFS(int start, vector<vector<int>> gameWinLose) {
    for (int i = 0; i < gameWinLose[start].size(); i++) {
        if (!isVisited[gameWinLose[start][i]]) {
            isVisited[gameWinLose[start][i]] = true;
            DFS(gameWinLose[start][i], gameWinLose);
        }
    }
    return;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    //������ �̰���� �ܹ��� �׷��� �������� ����
    vector<vector<int>> win;
    for (int i = 0; i <= n; i++) {
        vector<int> temp;
        win.push_back(temp);
    }
    for (int i = 0; i < results.size(); i++) {
        win[results[i][0]].push_back(results[i][1]);
    }

    //�������� ������ �ܹ��� �׷��� �������� ����
    vector<vector<int>> lose;
    for (int i = 0; i <= n; i++) {
        vector<int> temp;
        lose.push_back(temp);
    }
    for (int i = 0; i < results.size(); i++) {
        lose[results[i][1]].push_back(results[i][0]);
    }

    //�� ��忡�� �����Ͽ� �̱� ���� �� ��带 DFS�������� Ž���Ͽ� 
    //��� ��带 �湮�ߴٸ� �̱�ų� �� ����� ��� �ִٴ� ��
    //�ϳ��� �湮ó���� �ȵǾ��ִٸ� �������ʹ� ����Ǿ����� �ʾ� �� ������ �������δ� �� �� ����.
    for (int i = 1; i <= n; i++) {
        bool isCheck = true;
        //�湮 ó�� �ʱ�ȭ
        fill(&isVisited[1], &isVisited[n + 1], false);
        isVisited[i] = true;
        DFS(i, win);
        DFS(i, lose);
        for (int j = 1; j <= n; j++) {
            if (!isVisited[j]) {
                isCheck = false;
                break;
            }
        }
        if (isCheck)
            answer++;
    }
    return answer;
}
