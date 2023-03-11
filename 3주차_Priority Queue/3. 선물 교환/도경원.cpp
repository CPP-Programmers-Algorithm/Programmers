#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// 출력초과 // 정답은 맞음
void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    int sCount;
    string answer = "";

    vector<vector<int>> node;
	vector<int>	gift;
    queue<int> q;

    int n;
    cin >> n;
    gift.resize(n);
    node.resize(n);
    
    sCount = n;

    // 선물 갯수 축적
    // 노드저장
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            int temp;
            cin >> temp;

            gift[temp - 1] += 1;        //선물갯수 축적
            node[i].push_back(temp - 1);          // 노드저장

        }
    }

    for (size_t i = 0; i < n; i++)
    {
        if (gift[i] < 2) { q.push(i);}
        // 받은 선물이 2보다 작으면 탈락자 명단
    }

    while (!q.empty()) {

        int idx = q.front();
        gift[   node[idx][0]  ]--;           // 부실노드가 가리키는 노드의 선물이 사라진다
        gift[   node[idx][1]  ]--;           // 부실노드가 가리키는 노드의 선물이 사라진다

        q.pop();
        sCount--;                               //성공한 학생수를 감소

        for (size_t i = 0; i < 2; i++)          // 연결된 노드가 함께 무너지는지 검사
        {
            int linkNodeIdx = node[idx][i];
            for (size_t j = 0; j < 2; j++)
            {
                if (node[linkNodeIdx][j] == idx) {
                    q.push(linkNodeIdx);            // 부실노드가 가르키는 노드가 부실노드를 가르키고 있다면
                }                                   // 이 노드도 부실노드에 넣는다
            }   
        }
    }

    answer.append(to_string(sCount));
    if (sCount == 0) { cout << answer; return 0; }                  // 성공학생이 없으면 여기서 끝냄


    answer.append("\n");
    for (size_t i = 0; i < n; i++)
    {
        if (gift[i] == 2) {
            answer.append(to_string(i+1) + " "); // 인덱스가 아닌 요소를 나타내므로 +1 해준다
        }
    }

    cout << answer;
	return 0;
}