#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> A;
int main() {
	int N;
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}
	int x, y;
	cin >> x >> y;
	int relNum;
	relNum = x * N / 100;
	sort(A.begin(), A.end());
	int b = 0;
	for (int i = 1; i <= N; i++) {
		if (A[N - i] < y)break;
		b++;
	}
	cout << relNum << " " << b << endl;
}
