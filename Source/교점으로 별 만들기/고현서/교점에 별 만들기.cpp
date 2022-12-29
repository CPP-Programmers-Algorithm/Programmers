#include<iostream>
#include<string>
#include<vector>

#define INF 0x3f3f3f3f
#define MAX 10000000001
#define MIN -10000000001
using namespace std;


vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;

    vector < vector<long long >> spots;
    long long xMin = MAX;
    long long xMax = MIN;
    long long yMin = MAX;
    long long yMax = MIN;
    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long b = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            if (b == 0) continue;
            long long x = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
            long long y = (long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2];
            if (x % b != 0 || y % b != 0) continue;

            x /= b;
            y /= b;
            //정수라면 spots 벡터 안에 넣어두기
            vector<long long> sp;

            xMax = max(xMax, (long long)x);
            yMax = max(yMax, (long long)y);
            xMin = min(xMin, (long long)x);
            yMin = min(yMin, (long long)y);

            sp.push_back((long long)x);
            sp.push_back((long long)y);

            spots.push_back(sp);
        }
    }
    long long row = yMax - yMin + 1;
    long long col = xMax - xMin + 1;
    string temp(col, '.');
    answer.assign(row, temp);

    for (int i = 0; i < spots.size(); i++) {
        answer[yMax - spots[i][1]][spots[i][0] - xMin] = '*';
    }
    return answer;
}