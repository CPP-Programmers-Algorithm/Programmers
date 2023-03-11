#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> s;
int len;
bool check[8];

void dfs(vector<string>& u_id, vector<string>& b_id, int i, int num) { // vector의 주소를 전달하여 참조가 가능하게 한다
    if (i == len) {                                                    // ?? 의 idx를 매개변수로 전달한다
        s.emplace(num);
        return;
    }

    for (int j = 0; j < u_id.size(); j++) {
        int z;
        if (u_id[j].size() != b_id[i].size())           // 길이가 같지 않으면 넘어간다
            continue;

        if (check[j] == true)                           // 이미 검사한 것이면 넘어간다
            continue;

        for (z = 0; z < u_id[j].size(); z++) {          //u_id 검사하기
            if (b_id[i][z] == '*')                      //*이면 넘어간다
                continue;
            if (u_id[j][z] != b_id[i][z])               //다르면 break
                break;
        }                                               

        if (z == u_id[j].size()) {                      // 위 검사를 넘어 z가 u_id의 길이와 똑같아졌다면
            check[j] = true;                            // banded 회원
            dfs(u_id, b_id, i + 1, num | (1 << j));     // 비트연산
            check[j] = false;
        }
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    len = banned_id.size();
    dfs(user_id, banned_id, 0, 0);
    return s.size();
}


//https://hwan-shell.tistory.com/158
