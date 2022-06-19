#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m;
// 연구소 상태
int lab[8][8];
// 바이러스 퍼짐 여부
bool visited[8][8];
// 연구소에 있는 벽의 총 갯수
int walls;
// 안전영역 최대크기
int result;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
// 바이러스가 퍼졌을때 연구소에 있는 2의 갯수 구하기
int fillVirus(queue<pair<int, int>>& virusPos, int virus) {
	while (!virusPos.empty()) {
		int x = virusPos.front().first;
		int y = virusPos.front().second;
		virusPos.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			// 연구소를 벗어나면 continue
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)continue;
			// 방문하고자 하는 곳이 0이고 아직 바이러스가 안퍼진 곳이면
			if (lab[nextY][nextX] == 0 && visited[nextY][nextX] == 0) {
				// 해당장소 queue에 넣고 visited체크, virus갯수 증가
				virusPos.push(make_pair(nextX, nextY));
				visited[nextY][nextX] = true;
				virus++;
			}
		}
	}
	return virus;
}
// 안전 영역 넓이 구하기
void calcArea() {
	queue<pair<int, int>> virusPos;
	int virus = 0;
	memset(visited, 0, sizeof(visited));
	// bfs를 위해 바이러스가 있는곳 queue에 넣기
	// visited, virus 계산
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			if (lab[i][j] == 2) {
				virusPos.push(make_pair(j, i));
				visited[i][j] = true;
				virus++;
			}
	// 안전영역 = 전체넓이 - (벽의 총 갯수 + virus의 갯수)
	int ret = n * m - (walls + fillVirus(virusPos, virus));
	result = max(result, ret);
}
// 벽 설치
void constructWall(int wall, int here) {
	// 벽 설치 다했으면 안전영역 계산
	if (wall == 0) {
		calcArea();
		return;
	}
	int area = n * m;
	// 더 이상 벽을 설치할 곳이 없는 경우 return
	if (here >= area) return;
	int x = here % m;
	int y = here / m;
	// 현재 영역이 0이면 벽을 설치 하는 경우
	if (lab[y][x] == 0) {
		// 벽 설치하고 다음 영역으로 넘어감
		lab[y][x] = 1; walls++;
		constructWall(wall - 1, here + 1);
		// 원상복구
		lab[y][x] = 0; walls--;
	}
	// 현재 영역은 벽을 설치 안하고 다음 영역으로 넘어가는 경우
	constructWall(wall, here + 1);
}
int main() {
	cin >> n >> m;
	walls = result = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 1)
				walls++;	
		}
	constructWall(3, 0);
	cout << result << endl;
}
