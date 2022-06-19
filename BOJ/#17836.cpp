#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, t;
// 성의 정보
int castle[100][100];
// cache[y][x][검을 가졌는지] = 검을 갖고(or갖지 않고) (y,x)를 처음 방문했을때 시간
int cache[100][100][2];
// 한 칸씩 이동
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
// queue에 담을 구조체
struct Data {
	int x, y;
	int time;
	bool hasGram;
};
int rescue() {
	// 처음엔 0초
	cache[0][0][false] = 0;
	// bfs를 위한 queue
	queue<Data> q;
	// 용사의 처음 상태 push
	q.push({ 0,0,0,false });
	while (!q.empty()) {
		// 현재 상태 저장
		int curY = q.front().y; int curX = q.front().x;
		int curTime = q.front().time; bool curHas = q.front().hasGram;
		q.pop();
		// 각각 4가지 방향으로 이동할 경우
		for (int i = 0; i < 4; i++) {
			// 다음 상태 계산
			int nextY = curY + dy[i]; 
			int nextX = curX + dx[i];
			int nextTime = curTime + 1;
			// 현재 검을 갖고 있거나 검이 있는 칸을 가거나
			bool nextHas = (curHas || castle[nextY][nextX] == 2);
			// 공주를 구할 수 있으면 해당 시간을 return
			if (nextY == n && nextX == m)return nextTime;
			// castle을 안벗어나고
			if ((nextY >= 0 && nextY <= n && nextX >= 0 && nextX <= m)) 
				// 검을 갖고 있거나 벽에 안부딪히게
				if (curHas || castle[nextY][nextX] != 1) {
					// 이미 지나온 길은 되돌아갈 필요없음
					if (cache[nextY][nextX][nextHas] == -1) {
						q.push({ nextX, nextY, nextTime, nextHas });
						cache[nextY][nextX][nextHas] = nextTime;
					}
				}
		}
	}
	// 공주를 못구하는 경우
	return -1;
}
int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> castle[i][j];
	n--; m--;
	memset(cache, -1, sizeof(cache));
	int result = rescue();
	// 공주를 제한시간내에 못구하는 경우
	if (result == -1 || result > t)
		cout << "Fail" << endl;
	else
		cout << result << endl;
}
