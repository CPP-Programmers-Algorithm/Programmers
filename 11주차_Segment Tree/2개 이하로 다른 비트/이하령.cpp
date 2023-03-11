#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;

ll go(ll n) {
    ll sum = 0, t = 1, count = 0, tmp = n;
    while(tmp & 1) {
        sum += t;
        t *= 2;
        tmp >>= 1;
        count++;
    }
    if (count == 0) return n + (1LL << count);
    return n + (1LL << count) - (1LL << (count-1));

}

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;
    for(ll n : numbers) {
        answer.push_back(go(n));
    }
    return answer;
}

int main() {
    vector<ll> v = {2, 7};
    vector<ll> a = solution(v);
    for(ll i : a) printf("%lld\n", i);
}