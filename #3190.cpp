#include<iostream>
#include<vector>
#include<deque>
#include<list>
using namespace std;
int n;
// 애플 위치
list<pair<int, int>> apple;
// 뱀이 있는 좌표
deque<pair<int, int>> snake;
// 방향전환
deque<pair<int, bool>> dirChange;
// 방향전환에 따른 뱀의 이동방향
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dummy() {
	// 처음에는 오른쪽으로 전진
	int dir = 0;
	// 1초는 무조건 버팀
	int ret = 1;
	// 뱀의 머리 좌표
	int curX = 0, curY = 0;
	snake.push_back(make_pair(0, 0));
	while (true) {
		// 다음칸에 애플이 있는지 없는지
		bool thereApple = false;
		// 다음으로 가야할 칸에 대한 좌표
		int nextX = curX + dx[dir];
		int nextY = curY + dy[dir];
		// 보드를 벗어나면 게임오버
		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
			return ret;
		// 뱀이 자기자신에게 부딪히는 경우
		for (int i = 0; i < snake.size(); i++) 
			if (nextX == snake[i].first && nextY == snake[i].second)
				return ret;
		// 다음칸에 애플이 있으면 일단 그 칸에 있는 애플을 지우고 thereApple=true
		for(list<pair<int, int>>::iterator it=apple.begin(); it!=apple.end(); it++)
			if (nextX == it->first && nextY == it->second) {
				thereApple = true;
				apple.erase(it);
				break;
			}
		// 이번턴에 방향전환을 해야되면 입력에 맞게 방향 전환
		if (!dirChange.empty() && ret == dirChange.front().first) {
			if (dirChange.front().second) dir = (dir + 4 + 1) % 4;
			else dir = (dir + 4 - 1) % 4;
			dirChange.pop_front();
		}
		// 다음칸으로 전진
		snake.push_back(make_pair(nextX, nextY));
		// 다음칸에 애플이 없으면 꼬리도 한칸 전진
		if (!thereApple)
			snake.pop_front();
		// 머리좌표 옮기기
		curX = nextX; curY = nextY;
		// 시간흐름
		ret++;
	}
}
int main() {
	int appleNum, dirChangeNum;
	cin >> n;
	cin >> appleNum;
	for (int i = 0; i < appleNum; i++) {
		int appleX, appleY;
		cin >> appleY >> appleX;
		apple.push_back(make_pair(appleX - 1, appleY - 1));
	}
	cin >> dirChangeNum;
	for (int i = 0; i < dirChangeNum; i++) {
		int sec;
		char dir;
		cin >> sec >> dir;
		if (dir == 'D')
			dirChange.push_back(make_pair(sec, true));
		else
			dirChange.push_back(make_pair(sec, false));
	}
	cout << dummy() << endl;
}
