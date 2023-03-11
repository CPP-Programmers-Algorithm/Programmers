#include <bits/stdc++.h>
using namespace std;

int cards[500000];
int targets[500000];

int GetLowerIdx(int targetNum, int len) {
	int st = 0;
	int en = len - 1;
	int idx = 0;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (cards[mid] < targetNum) { st = mid + 1; }
		else if (cards[mid] >= targetNum) { en = mid - 1; }

		idx = st;
	}
	return idx;
}

int GetUpperIdx(int targetNum, int len) {
	int st = 0;
	int en = len - 1;
	int idx = 0;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (cards[mid] <= targetNum) { st = mid + 1; }
		else if (cards[mid] > targetNum) { en = mid - 1; }

		idx = st;
	}
	return idx;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cardCount; cin >> cardCount;

	for (int i = 0; i < cardCount; i++) cin >> cards[i];
	sort(cards, cards + cardCount);

	int targetCount; cin >> targetCount;

	for (int i = 0; i < targetCount; i++) cin >> targets[i];

	for (int i = 0; i < targetCount; i++) {
		int result;
		result = GetUpperIdx(targets[i], cardCount) - GetLowerIdx(targets[i], cardCount);
		cout << result << ' ';
	}

}