using namespace std;

long long solution(int w, int h) {
	long long answer = (long long)w * h - (w + h);
	while (h != 0) {
		int c = w % h;
		w = h;
		h = c;
	}
	return answer + w;
}