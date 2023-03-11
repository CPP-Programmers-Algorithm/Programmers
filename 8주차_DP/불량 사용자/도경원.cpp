#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> s;
int len;
bool check[8];

void dfs(vector<string>& u_id, vector<string>& b_id, int i, int num) { // vector�� �ּҸ� �����Ͽ� ������ �����ϰ� �Ѵ�
    if (i == len) {                                                    // ?? �� idx�� �Ű������� �����Ѵ�
        s.emplace(num);
        return;
    }

    for (int j = 0; j < u_id.size(); j++) {
        int z;
        if (u_id[j].size() != b_id[i].size())           // ���̰� ���� ������ �Ѿ��
            continue;

        if (check[j] == true)                           // �̹� �˻��� ���̸� �Ѿ��
            continue;

        for (z = 0; z < u_id[j].size(); z++) {          //u_id �˻��ϱ�
            if (b_id[i][z] == '*')                      //*�̸� �Ѿ��
                continue;
            if (u_id[j][z] != b_id[i][z])               //�ٸ��� break
                break;
        }                                               

        if (z == u_id[j].size()) {                      // �� �˻縦 �Ѿ� z�� u_id�� ���̿� �Ȱ������ٸ�
            check[j] = true;                            // banded ȸ��
            dfs(u_id, b_id, i + 1, num | (1 << j));     // ��Ʈ����
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
