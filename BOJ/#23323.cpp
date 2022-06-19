#include<iostream>
using namespace std;
int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		long long n, m;
		cin >> n >> m;
		int exp = 0;
		// 소의 체력이 2^n + x 일때 소는 먹이없이 n일 버틸 수 있다.
		while (n != 0) {
			n /= 2;
			exp++;
		}
		// 먹이를 가장 효율적으로 주는 방법은 체력이 1일때 하나씩 주는것이다. 
		cout << exp + m << endl;
	}
}
