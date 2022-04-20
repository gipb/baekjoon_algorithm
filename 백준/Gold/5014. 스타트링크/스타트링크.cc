#include <iostream>
using namespace std;

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	int flag = 0;
	int cnt = 0;
	if (G > S && !U) flag = 1;
	else if (G < S && !D) flag = 1;
	else if (U % 2 == 0 && D % 2 == 0 && abs(G - S) % 2) flag = 1;
	else if (G>S) {
		while (true) {
			if (G == S) break;
			if (S + U > F && S <= D) {
				flag = 1;
				break;
			}
			if (G > S && F >= S + U){
				S += U;
				cnt++;
			}
			else {
				S -= D;
				cnt++;
			}
		}
	}
	else if (G < S) {
		while (true) {
			if (G == S) break;
			if (S + U > F && S <= D) {
				flag = 1;
				break;
			}
			if (G<S && S>D) {
				S -= D;
				cnt++;
			}
			else {
				S += U;
				cnt++;
			}
		}
	}
	if (flag) cout << "use the stairs";
	else cout << cnt;
}