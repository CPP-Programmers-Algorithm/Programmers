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

    //��� ���� �Ÿ��αⰡ �Ѹ��̶� �̷������ �ʴ´ٸ� return 0
    for (int i = 0; i < signs.size() - 1; i++) {
        for (int j = i + 1; j < signs.size(); j++) {
            //����ư �Ÿ��� 2�����ΰ�
            if (abs(signs[i].x - signs[j].x) + abs(signs[i].y - signs[j].y) <= 2) {
                //�� ���̿� ���� �ִ��� Ȯ��
                //x��ǥ�� ���� ��� �� ���� y��ǥ���� ���� �ִ��� Ȯ��
                if (signs[i].x == signs[j].x) {
                    if (chars[abs(signs[i].y + signs[j].y) / 2][signs[i].x] != 'X')
                        return 0;
                }
                //y��ǥ�� ���� ��� �� ���� x��ǥ���� ���� �ִ��� Ȯ��
                else if (signs[i].y == signs[j].y) {
                    if (chars[signs[i].y][abs(signs[i].x + signs[j].x) / 2] != 'X')
                        return 0;
                }
                //(2�� ����� x��ǥ, 1������� y��ǥ)��(1�� ����� x��ǥ, 2������� y��ǥ)�� ��Ƽ���� �ִ��� Ȯ�� 
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
                //����� �ִ� ���� ��ǥ�� �־��ش�.
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