#include<iostream>
#include<vector>
#include<math.h>

#define INF 0x3f3f3f3f
#define MAX 1001
#define MIN -1001
using namespace std;

struct Sign {
    int x;
    int y;
};
int Check(vector<vector<char>> chars, vector<Sign> signs) {
    if (signs.size() == 0) return 1;

    //사람 간의 거리두기가 한명이라도 이루어지지 않는다면 return 0
    for (int i = 0; i < signs.size() - 1; i++) {
        for (int j = i + 1; j < signs.size(); j++) {
            //맨해튼 거리가 2이하인가
            if (abs(signs[i].x - signs[j].x) + abs(signs[i].y - signs[j].y) <= 2) {
                //둘 사이에 벽이 있는지 확인
                //x좌표가 같을 경우 둘 사이 y좌표간의 벽이 있는지 확인
                if (signs[i].x == signs[j].x) {
                    if (chars[abs(signs[i].y + signs[j].y) / 2][signs[i].x] != 'X')
                        return 0;
                }
                //y좌표가 같을 경우 둘 사이 x좌표간의 벽이 있는지 확인
                else if (signs[i].y == signs[j].y) {
                    if (chars[signs[i].y][abs(signs[i].x + signs[j].x) / 2] != 'X')
                        return 0;
                }
                //(2번 사람의 x좌표, 1번사람의 y좌표)와(1번 사람의 x좌표, 2번사람의 y좌표)에 파티션이 있는지 확인 
                else if (chars[signs[j].y][signs[i].x] != 'X' || chars[signs[i].y][signs[j].x] != 'X') {
                    return 0;
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        vector<vector<char>> placesChars;
        vector<Sign> personSign;
        for (int j = 0; j < places[i].size(); j++) {
            string str = places[i][j];
            vector<char> chars;
            for (int k = 0; k < str.length(); k++) {
                chars.push_back(str[k]);
                //사람이 있는 곳은 좌표를 넣어준다.
                if (str[k] == 'P') {
                    personSign.push_back({ k,j });
                }
            }
            placesChars.push_back(chars);
        }
        answer.push_back(Check(placesChars, personSign));
    }
    return answer;
}