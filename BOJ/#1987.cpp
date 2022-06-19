#include<iostream>
using namespace std;
char map[20][20];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int R, C;
// 인자로 넘어온 알파벳의 비트마스크 표현 return
int charTobit(char c) {
	int x = c - 'A';
	return (1 << x);
}
// 맵 범위 검사
bool boundValidation(int x, int y) {
	if (x < 0 || x >= C)
		return false;
	if (y < 0 || y >= R)
		return false;
	return true;
}
// 지나온 알파벳중에 있는지 비트마스크를 이용한 검사
bool alreadyHave(char c, int state) {
	int next = charTobit(c);
	if ((state & next) > 0)
		return true;
	return false;
}
// dfs를 이용
int tracking(int state, int curX, int curY) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = curX + dx[i];
		int nextY = curY + dy[i];
		// 다음 이동지역이 범위를 벗어나거나 지나온 알파벳중에 있으면 무시
		if (boundValidation(nextX, nextY)&&!alreadyHave(map[nextY][nextX],state)) {
			// 다음 지역의 알파벳을 상태에 넣고 다음상태로 재귀
			int nextState = state | charTobit(map[nextY][nextX]);
			ret = max(ret, tracking(nextState, nextX, nextY) + 1);
		}
	}
	return ret;
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	cout << tracking(charTobit(map[0][0]), 0, 0);
}
