#include <iostream>
using namespace std;
long long Recur(int a, int b);
long long solution(int w, int h);
int main()
{
    cout << solution(8, 12);
}
long long Recur(int a, int b)
{
    
    if (b == 0)
    {
        return a;
    }
    else
    {
        return Recur(b, a % b);
    }
}
long long solution(int w, int h) {

    long long answer = 1;
    long long ww = w;
    long long hh = h;
    if (ww == hh)
    {
        answer = ww * hh - ww;
    }
    if (ww != hh)
    {
        if (ww > hh)
        {

      answer =  ww *hh -(ww+hh - Recur(ww, hh));
        }
        else
        {
        answer = ww * hh - (ww + hh - Recur(hh, ww));
        }
    }
    return answer;
}
