#include<iostream>
using namespace std;
int area[50][50];
int n, m;
// 청소한 횟수
int howMany;
// (r,c)에서 d방향을 바라보고 지금까지 turn번 돌았음
void clean(int r, int c, int d, int turn) {
	// 청소 안되있으면 한다
	if (area[r][c] == 0) {
		area[r][c] = 2;
		howMany++;
	}
	// 한바퀴 돌았는데 진전이 없으면 후진하거나 종료하거나
	if (turn == 4) 
		switch (d) {
			case 0:
				if (area[r + 1][c] == 1)
					return;
				return clean(r + 1, c, d, 0);
			case 1:
				if (area[r][c - 1] == 1)
					return;
				return clean(r, c - 1, d, 0);
			case 2:
				if (area[r - 1][c] == 1)
					return;
				return clean(r - 1, c, d, 0);
			case 3:
				if (area[r][c + 1] == 1)
					return;
				return clean(r, c + 1, d, 0);
		}
	// 왼쪽방향
	int left;
	if (d == 0)
		left = 3;
	else
		left = d - 1;
	// 돌아서 전진한다음 청소하거나, 그냥 돌기만 하거나
	switch (left) {
		case 0:
			if (area[r - 1][c] == 0)
				return clean(r - 1, c, 0, 0);
			return clean(r, c, left, turn + 1);
		case 1:
			if (area[r][c + 1] == 0)
				return clean(r, c + 1, 1, 0);
			return clean(r, c, left, turn + 1);
		case 2:
			if (area[r + 1][c] == 0)
				return clean(r + 1, c, 2, 0);
			return clean(r, c, left, turn + 1);
		case 3:
			if (area[r][c - 1] == 0)
				return clean(r, c - 1, 3, 0);
			return clean(r, c, left, turn + 1);
	}
}
int main() {
	cin >> n >> m;
	int x, y, dir;
	cin >> y >> x >> dir;
	howMany = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> area[i][j];
	clean(y, x, dir, 0);
	cout << howMany << endl;
}
