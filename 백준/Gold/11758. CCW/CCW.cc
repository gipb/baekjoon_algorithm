#include <iostream>
using namespace std;

int main() {
	int x1, x2, x3;
	int y1, y2, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int ans;

	// 기울기 비교 시 실수형을 사용하면 부정확할 수 있으므로
	int tmp1 = (y2 - y1)*(x3 - x2);
	int tmp2 = (y3 - y2)*(x2 - x1);

	// 기울기가 같은 경우
	if (tmp1 == tmp2) ans = 0;

	else if (x2 == x1) {
		if (y2 > y1) {
			if (x3 > 0) ans = -1;
			else ans = 1;
		}
		else {
			if (x3 > 0) ans = 1;
			else ans = -1;
		}
	}
	else {
		if (tmp1 > tmp2) ans = -1;
		else ans = 1;
	}
	
	cout << ans;

	return 0;
}