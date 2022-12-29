#include<iostream>
#include<vector>
#include<queue>

#define INF 0x3f3f3f3f
#define MAX 1001
#define MIN -1001
using namespace std;

int cost[20001];
bool isVisited[20001];
vector<vector<int>> node;
queue<int> startNode;
void BFS(int start) {
    for (int i = 0; i < node[start].size(); i++) {
        if (!isVisited[node[start][i]]) {
            cost[node[start][i]] = cost[start] + 1;
            isVisited[node[start][i]] = true;
            startNode.push(node[start][i]);
        }
    }
    for (int i = 0; i < startNode.size(); i++) {
        int start = startNode.front();
        startNode.pop();
        BFS(start);
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i <= n; i++) {
        vector<int> vec;
        node.push_back(vec);
    }

    for (int i = 0; i < edge.size(); i++) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }

    isVisited[1] = true;
    BFS(1);
    int maxNum = 0;
    for (int i = 2; i <= n; i++) {
        if (maxNum < cost[i]) {
            maxNum = cost[i];
            answer = 1;
        }
        else if (maxNum == cost[i]) {
            answer++;
        }
    }
    return answer;
}