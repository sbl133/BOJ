#include<iostream>
#include<vector>
using namespace std;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
// dice[0]: 윗면, dice[1]: 북쪽을 바라보는 면, dice[2]: 동쪽을 바라보는 면
// dice[3]: 서쪽을 바라보는 면, dice[4]: 남쪽을 바라보는 면, dice[5]: 밑면
int dice[6] = { 0, };
int map[20][20];
int n, m;
int x = 0, y = 0;
vector<int> command;
void rollingDice() {
	// 명령을 순서대로 실행
	for (int i = 0; i < command.size(); i++) {
		int cy = y + dy[command[i] - 1];
		int cx = x + dx[command[i] - 1];
		// 지도 범위에 벗어나면 continue
		if (cy < 0 || cy >= n || cx < 0 || cx >= m)
			continue;
		x = cx; y = cy;
		// 서쪽으로 움직였을때
		if (command[i] == 2) {
			int d0 = dice[0], d2 = dice[2];
			int d3 = dice[3], d5 = dice[5];
			dice[0] = d2; dice[2] = d5;
			dice[3] = d0; dice[5] = d3;
		}
		// 동쪽으로 움직였을때
		else if (command[i] == 1) {
			int d0 = dice[0], d2 = dice[2];
			int d3 = dice[3], d5 = dice[5];
			dice[0] = d3; dice[2] = d0;
			dice[3] = d5; dice[5] = d2;
		}
		// 남쪽으로 움직였을때
		else if (command[i] == 4) {
			int d0 = dice[0], d1 = dice[1];
			int d4 = dice[4], d5 = dice[5];
			dice[0] = d1; dice[1] = d5;
			dice[4] = d0; dice[5] = d4;
		}
		// 북쪽으로 움직였을때
		else if (command[i] == 3) {
			int d0 = dice[0], d1 = dice[1];
			int d4 = dice[4], d5 = dice[5];
			dice[0] = d4; dice[1] = d0;
			dice[4] = d5; dice[5] = d1;
		}
		if (map[y][x] == 0)
			map[y][x] = dice[5];
		else {
			dice[5] = map[y][x];
			map[y][x] = 0;
		}
		cout << dice[0] << endl;
	}
}
int main() {
	int k;
	cin >> n >> m >> y >> x >> k;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		command.push_back(tmp);
	}
	rollingDice();
}
