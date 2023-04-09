#include <string>
#include <vector>

using namespace std;

int getNum(int n) {
    int ret = 0;
    while (n > 0) {
        n /= 10;
        ret++;
    }
    return ret;
}

int solution(string s) {
    int answer = 1001, ix, a, total = 0;
    string las = "", tmp;

    for(int i = 1; i <= s.size() / 2; i++) { // 자를 단위 i
        ix = 0; a = 0;
        while (ix < s.size()) {
            for(int j = ix; j < ix + i and j < s.size(); j++) tmp += s[j];
            ix += i;
            if (tmp == las) total++;
            else {
                if (total > 0) {
                    a += getNum(++total);
                    total = 0;
                }
                a += tmp.size(); // 이전에 겹친 글자가 없을 경우, tmp 크기만 더해줌
            }
            las = tmp; tmp = "";
        }
        if (total > 0) {
            a += getNum(++total);
            total = 0;
        }
        answer = min(answer, a);
    }
    if (s.size() == 1) answer = 1;
    return answer;
}