#include <cstdio>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    ll mod = a % b;

    while (mod > 0) {
        a = b;
        b = mod;
        mod = a % b;
    }
    return b;
}

long long solution(int w, int h) {
    ll g = gcd(w, h);
    return ll(w*ll(h)) - (w+h-g);
}