#include <string>
#include <vector>

using namespace std;

int minL[1000001];
int minR[1000001];

int solution(vector<int> a) {
    int answer = 0;
    //시작최소값설정
    minL[0] = a[0];
    minR[a.size() - 1] = a[a.size() - 1];

    //왼쪽최소값갱신
    for (int i = 1; i < a.size(); i++)
    {
        if (minL[i - 1] > a[i]) minL[i] = a[i];
        else minL[i] = minL[i - 1];
    }

    //오른쪽 최소값갱신
    for (int i = a.size()-2; i >= 0; i--)
    {
        if (minR[i + 1] > a[i]) minR[i] = a[i];
        else minR[i] = minR[i + 1];
    }

    // 목표 idx값과 minL과 minR을 비교
    // 둘 모두보다 작다면 살아나을 수 없음
    // 작을때 살아남을 수 있는 경우의 수를 소진했기 때문에
    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= minL[i] || a[i] <= minR[i]) answer++;
    }

    return answer;
}



//