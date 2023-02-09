#include <cstdio>
#include <queue>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, st = 1, en;
    for(int i : stations) {
        en = i - w - 1;
        if (en > n) en = n;
        if (en >= st) {
            answer += ((en - st + 1) / (2*w + 1));
            answer += (((en - st + 1) % (2*w + 1)) ? 1 : 0);
        }
        st = i + w + 1;
    }

    if (en != n) {
            en = n;
            if (en >= st) {
                answer += ((en - st + 1) / (2*w + 1));
                answer += (((en - st + 1) % (2*w + 1)) ? 1 : 0);
            }


    }
    return answer;
}