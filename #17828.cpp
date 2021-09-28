#include<iostream>
using namespace std;
int main() {
	int n, x;
	cin >> n >> x;
	// 주어진 길이로 화폐를 표현할 수 없다면 ! 출력
	if (x < n || x >(26 * n))
		cout << "!" << endl;
	else {
		// Z의 갯수, A의 갯수, 남은 화폐가치
		int zNum, aNum, remain = 0;
		for (zNum = 0; zNum <= n; zNum++)
			// 더 이상 Z를 넣을 수 없다면
			if (n - zNum > x - 26 * zNum) {
				// Z를 넣고 남은 화폐가치를 측정
				remain = x - (26 * (zNum - 1));
				break;
			}
		zNum = zNum - 1;
		// A의 갯수 = n - Z의 갯수 - A와 Z사이에 들어갈 중간 문자 하나
		aNum = n - zNum -1;
		// 중간 문자는 남은 화폐가치에 A(=1)의 갯수를 뺀것과 같다
		int midNum = remain - aNum;
		for (int i = 0; i < aNum; i++)
			cout << 'A';
		// Z로만 채워져 있으면 중간 문자 없음
		if (zNum != n) {
			char midMoney = 'A' + midNum - 1;
			cout << midMoney;
		}
		for (int i = 0; i < zNum; i++)
			cout << 'Z';
	}
}
