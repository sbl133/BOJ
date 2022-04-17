#include<iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int x, y, dist;
		cin >> x >> y;
		dist = y - x;
		// 장치 작동 횟수
		int count = 0;
		while (dist > 0) {
			// (장치 작동 횟수 / 2 + 1) 거리 개수를 이동할 수 있다.
			dist = dist - (count / 2 + 1);
			count++;
			if (dist <= 0)
				break;
			dist = dist - (count / 2 + 1);
			count++;
		}
		cout << count << endl;
	}
}
