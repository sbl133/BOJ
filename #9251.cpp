#include<iostream>
#include<cstring>
using namespace std;
string A, B;
int cache[1000][1000];
int lcs(int a, int b) {
	// a또는 b가 끝에 다다르면 LCS를 만들 수 없다.
	if (a == A.length() || b == B.length()) return 0;
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	ret = 0;
	// A[a] == B[b]이면 해당문자를 LCS에 추가하거나
	if (A[a] == B[b]) 
		ret = max(ret, lcs(a + 1, b + 1) + 1);
	// B에 다음문자로 LCS를 만들거나
	ret = max(ret, lcs(a, b + 1));
	// A에 다음문자로 LCS를 만든것 중에서 제일 큰걸 리턴
	ret = max(ret, lcs(a + 1, b));
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> A >> B;
	cout << lcs(0, 0) << endl;
}
