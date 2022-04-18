#include<iostream>
using namespace std;
char map[20][20];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int R, C;
int charTobit(char c) {
	int x = c - 'A';
	return (1 << x);
}
bool boundValidation(int x, int y) {
	if (x < 0 || x >= C)
		return false;
	if (y < 0 || y >= R)
		return false;
	return true;
}
bool alreadyHave(char c, int state) {
	int next = charTobit(c);
	if ((state & next) > 0)
		return true;
	return false;
}
int tracking(int state, int curX, int curY) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = curX + dx[i];
		int nextY = curY + dy[i];
		if (boundValidation(nextX, nextY)&&!alreadyHave(map[nextY][nextX],state)) {
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
