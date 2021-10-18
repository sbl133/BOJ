#include<iostream>
using namespace std;
// 최대 자릿수, 최소 자릿수
int resultBig, resultSmall;
// 이진수의 길이
int n;
void Mr_Binary(string str) {
	// 최대값의 가장 높은자리의 자릿수, 최솟값의 가장 높은자리의 자릿수
	int maxHigh = 0, minHigh = 0;
	// maxHigh, minHigh 이하의 자리에 1이 하나라도 있나?
	bool maxIsLow = false, minIsLow = false;
	// str값을 2^0자리부터 탐색
	for (int i = str.size()-1; i >= 0; i--) {
		// 1이 오면 최댓값 최솟값 모두 갱신
		if (str[i] == '1') {
			// 이전에 최고 자릿수가 있었으면 최고자리 미만의 자리에 1이 하나이상 존재
			if (maxHigh != 0) maxIsLow = true;
			if (minHigh != 0) minIsLow = true;
			// 최댓값, 최소값의 최고 자릿수 갱신
			maxHigh = minHigh = n - i;
		}
		// ?이 오면 최댓값만 갱신
		else if (str[i] == '?') {
			if (maxHigh != 0) maxIsLow = true;
			maxHigh = n - i;
		}
	}
	// 최댓값 처리
	if (maxHigh == 0)
		resultBig = 1;
	// 최고 자리 미만의 자리에 1이 존재하지 않으면 최고자리수+n에서 1을 뺌
	else
		resultBig = maxIsLow ? maxHigh + n : maxHigh + n - 1;
	// 최솟값 처리
	if (minHigh == 0)
		resultSmall = 1;
	else
		resultSmall = minIsLow ? minHigh + n : minHigh + n - 1;
}
int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		string str;
		cin >> n;
		cin >> str;
		Mr_Binary(str);
		cout << resultBig << " " << resultSmall << endl;
	}

}
