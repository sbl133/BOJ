#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n, m;
int lab[8][8];
bool visited[8][8];
int virus;
int walls;
int result;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
int fillVirus(queue<pair<int, int>>& virusPos) {
	int ret = 0;
	while (!virusPos.empty()) {
		int x = virusPos.front().first;
		int y = virusPos.front().second;
		virusPos.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)continue;
			if (lab[nextY][nextX] == 0 && visited[nextY][nextX] == 0) {
				virusPos.push(make_pair(nextX, nextY));
				visited[nextY][nextX] = true;
				ret++;
			}
		}
	}
	return ret;
}
int calcArea() {
	queue<pair<int, int>> virusPos;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			if (lab[i][j] == 2) {
				virusPos.push(make_pair(j, i));
				visited[i][j] = true;;
			}
	int ret = n * m - (walls + 3 + fillVirus(virusPos) + virus);
	return ret;
}
int laboratory(int wall, int next) {
	int area = n * m;
	if (next >= area) return -1;
	if (wall == 0) return calcArea();
	int x = next % m;
	int y = next / m;
	if (lab[y][x] == 0) {
		lab[y][x] = 1;
		result = max(result, laboratory(wall - 1, next + 1));
		lab[y][x] = 0;
	}
	result = max(result, laboratory(wall, next + 1));
	return result;
}

int main() {
	scanf("%d %d", &n, &m);
	virus = 0;
	result = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 1)
				walls++;
			else if (lab[i][j] == 2) 
				virus++;	
		}
	printf("%d\n", laboratory(3, 0));
}
