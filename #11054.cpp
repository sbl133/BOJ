#include<iostream>
#include<cstring>
using namespace std;
// DP의 메모이제이션을 위한 cache
int cache[1001][1001][2];
int s[1000];
int n;
// curPos: 현재index위치, lastNum: 가장 최근에 고른 숫자
// isDec: 현재 만들고 있는 바이토닉이 증가중인가 감소중인가
int bitonic(int curPos, int lastNum, bool isDec) {
	// 기저사례(수열을 다 훑었으면 return 0)
	if (curPos == n)
		return 0;
	int& ret = cache[curPos][lastNum][isDec];
	// 이전에 결과값이 cache에 있으면 활용
	if (ret != -1)
		return ret;
	ret = 0;
	// 수열s에서 curPos번째 숫자를 고르지 않을 경우
	ret = bitonic(curPos + 1, lastNum, isDec);
	// 현재 만들고 있는 바이토닉이 증가중
	if (!isDec) {
		// 현재 숫자가 최근에 고른 숫자보다 큰경우
		if (lastNum < s[curPos])
			ret = max(ret, bitonic(curPos + 1, s[curPos], isDec) + 1);
		// 현재 숫자가 최근에 고른 숫자보다 작은경우
		else if (lastNum > s[curPos])
			ret = max(ret, bitonic(curPos + 1, s[curPos], !isDec) + 1);
	}
	// 현재 만들고 있는 바이토닉이 감소중
	else if (isDec && lastNum > s[curPos])
		ret = max(ret, bitonic(curPos + 1, s[curPos], isDec) + 1);
	// 각 경우중에 가장 긴 바이토닉 길이 return
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	memset(cache, -1, sizeof(cache));
	cout << bitonic(0, 0, false) << endl;
}
