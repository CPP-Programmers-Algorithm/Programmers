#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<deque>
#include<map>
#include<vector>
#include<cmath>
#include<climits>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<math.h>
#include<memory>
#include<sstream>
#include<unordered_map>
#define INF 0x3f3f3f3f
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
}
string table[114] = { "h", "li", "na", "k", "rb", "cs", "fr", "be", "mg", "ca", "sr", "ba", "ra", "sc", "y", "ti", "zr", "hf", "rf", "la", "ac",
                  "v", "nb", "ta", "db", "ce", "th", "cr", "mo", "w", "sg", "pr", "pa", "mn", "tc", "re", "bh", "nd", "u", "fe", "ru", "os",
                  "hs", "pm", "np", "co", "rh", "ir", "mt", "sm", "pu", "ni", "pd", "pt", "ds", "eu", "am", "cu", "ag" ,"au", "rg", "gd", "cm",
                  "zn", "cd", "hg", "cn", "tb", "bk", "b", "al", "ga", "in", "tl", "dy", "cf", "c", "si", "ge", "sn", "pb", "fl", "ho", "es",
                  "n", "p", "as", "sb", "bi", "er", "fm", "o", "s", "se", "te", "po", "lv", "tm", "md", "f", "cl", "br", "i", "at", "yb", "no",
                  "he", "ne", "ar", "kr", "xe", "rn","lu", "lr" };

unordered_map<string, bool> TableInfo;
bool isVisited[50005];
bool NewDP(string str) {
    string start = "";
    queue<int> q;
    q.push(0);
    isVisited[0] = true;
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        if (idx == str.size())
            return true;
        string one = str.substr(idx, 1);
        string two = str.substr(idx, 2);

        if (TableInfo[one] && !isVisited[idx + 1]) {
            isVisited[idx + 1] = true;
            q.push(idx + 1);
        }
        if (TableInfo[two] && !isVisited[idx + 2]) {
            isVisited[idx + 2] = true;
            q.push(idx + 2);
        }
    }
    return false;
}
int main() {
    init();
    for (int i = 0; i < 114; i++) {
        TableInfo[table[i]] = true;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(isVisited, 0, sizeof(isVisited));
        string str;
        cin >> str;
        if (NewDP(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}