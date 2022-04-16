#include<iostream>
#include<queue>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char adj[1000][1000];
bool discover[1000][1000][2] = { 0, };
struct state {
	int cost, x, y;
	bool power;
	state(int cost, int x, int y, bool power) {
		this->cost = cost;
		this->x = x;
		this->y = y;
		this->power = power;
	}
};
// 범위에서 벗어나는 좌표인지 확인
bool boundValidation(int x, int y, int desX, int desY) {
	if (x<0 || x>desX)
		return false;
	if (y<0 || y>desY)
		return false;
	return true;
}
// (desX, desY)에 도착할때의 비용 return
int solve(int desX, int desY) {
	queue<state> q;
	q.push(state(0, 0, 0, true));
	discover[0][0][true] = true;
	int ret = 1;
	while (!q.empty()) {
		int cost = q.front().cost;
		int x = q.front().x;
		int y = q.front().y;
		bool power = q.front().power;
		q.pop();
		// 도착했다면 거리 return
		if (x == desX && y == desY) {
			return cost + 1;
		}
		// 현재 위치에서 상하좌우 검사
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			int nextCost = cost + 1;
			bool nextPower = power;
			// 범위에 벗어나지 않고, 벽이 아니거나 벽을 부술 수 있고, 방문한적이 없으면 방문예정
			if (boundValidation(nextX, nextY, desX, desY) &&
				(adj[nextY][nextX] == '0' || nextPower) && (discover[nextY][nextX][nextPower] == false)) {
				// 벽을 부수고 온거면 더 이상 벽을 못부숨
				if (adj[nextY][nextX] == '1') 
					nextPower = false;
				// 방문예정 목록에 추가 해놓음
				q.push(state(nextCost, nextX, nextY, nextPower));
				discover[nextY][nextX][nextPower] = true;
			}
		}
	}
	return -1;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> adj[i][j];
	cout << solve(m - 1, n - 1);
}
