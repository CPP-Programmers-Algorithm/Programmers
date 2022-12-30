#include<iostream>
#include<vector>

using namespace std;

//방문 처리할 전역변수
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

    //누구를 이겼는지 단방향 그래프 형식으로 정리
    vector<vector<int>> win;
    for (int i = 0; i <= n; i++) {
        vector<int> temp;
        win.push_back(temp);
    }
    for (int i = 0; i < results.size(); i++) {
        win[results[i][0]].push_back(results[i][1]);
    }

    //누구에게 졌는지 단방향 그래프 형식으로 정리
    vector<vector<int>> lose;
    for (int i = 0; i <= n; i++) {
        vector<int> temp;
        lose.push_back(temp);
    }
    for (int i = 0; i < results.size(); i++) {
        lose[results[i][1]].push_back(results[i][0]);
    }

    //각 노드에서 시작하여 이긴 노드와 진 노드를 DFS형식으로 탐색하여 
    //모든 노드를 방문했다면 이기거나 진 사람이 모두 있다는 것
    //하나라도 방문처리가 안되어있다면 누군가와는 연결되어있지 않아 그 노드와의 순위여부는 알 수 없다.
    for (int i = 1; i <= n; i++) {
        bool isCheck = true;
        //방문 처리 초기화
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
