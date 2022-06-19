#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0 , 0, 1, -1 };
// 앞으로 익을 토마토들의 목록을 저장하는 queue
queue<pair<int, int>> checkList;
int column, row;
int adj[1000][1000];
// 토마토 상자 초기 정보를 adj와 checkList에 저장
void init(int column, int row) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 1)
				checkList.push(make_pair(i, j));
		}
	// 날짜 구분을 위해 (-1, -1)을 checkList에 삽입
	checkList.push(make_pair(-1, -1));
}
// 상자 범위에 벗어나는지 확인
bool validate(int x, int y) {
	if (x < 0 || x >= column)
		return false;
	if (y < 0 || y >= row)
		return false;
	return true;
}
int bfs() {
	int ret = 0;
	// 익을 예정인 토마토가 없을때까지 반복
	while (!checkList.empty()) {
		int curRow = checkList.front().first;
		int curCol = checkList.front().second;
		checkList.pop();
		// 날짜 구분자를 만날경우
		if (curRow == -1 && curCol == -1) {
			// 더이상 익을 예정인 토마토가 없으면 break
			if (checkList.empty())
				break;
			// 날짜 구분자를 삽입
			checkList.push(make_pair(-1, -1));
			// 하루가 지남
			ret++;
			continue;
		}
		// 4방향으로 오늘 익은 토마토 주위 검사
		for (int i = 0; i < 4; i++) {
			int checkRow = curRow + y[i];
			int checkCol = curCol + x[i];
			// 다음날 익을 예정인 토마토인지 검사
			if (validate(checkCol, checkRow)&&adj[checkRow][checkCol]==0) {
				adj[checkRow][checkCol] = 1;
				checkList.push(make_pair(checkRow, checkCol));
			}
		}
	}
	// 상자 전체의 토마토가 다 익었는지 검사
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (adj[i][j] == 0)
				ret = -1;
	return ret;
}
int main() {
	cin >> column >> row;
	init(column, row);
	cout << bfs() << endl;;
}
