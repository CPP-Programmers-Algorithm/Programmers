#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int arr[100][100];
pii mx[100];

int main() {
    scanf("%d %d", &n, &m);

    memset(arr, 0x3f, sizeof(arr));
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if (i == j) continue;
            sum += arr[i][j];
        }
        mx[i] = {sum, i};
    }
    sort(mx, mx + n);
    printf("%d", mx[0].second + 1);
}