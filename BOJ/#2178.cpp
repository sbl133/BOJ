#include<iostream>
#include<queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;
bool discovered[100][100];
int map[100][100];
// 좌표 (x, y) 의 유효성 검사
bool validation(int x, int y) {
	// 지도에서 벗어났는지
	if (x < 0 || x >= m) return false;
	if (y < 0 || y >= n) return false;
	// 이미 발견된 곳인지
	if (discovered[y][x] == true) return false;
	// 가지 못하는 곳인지
	if (map[y][x] == 0) return false;
	return true;
}
// bfs를 통한 최단경로 찾기
int bfs() {
	queue<pair<int, pair<int,int>>> q;
	discovered[0][0] = true;
	q.push(make_pair(1, make_pair(0, 0)));
	while (!q.empty()) {
		// 현재 위치
		int cost = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		// 도착했으면 비용 return
		if (x == (m - 1) && y == (n - 1))
			return cost;
		q.pop();
		// 현재 위치에서 상하좌우 검사
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			int nextCost = cost + 1;
			if (!validation(nextX, nextY))
				continue;
			discovered[nextY][nextX] = true;
			q.push(make_pair(nextCost, make_pair(nextX, nextY)));
		}
	}
}
int main() {
	cin >> n >> m;
	char tmp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	cout << bfs();
}
