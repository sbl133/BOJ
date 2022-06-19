#include<iostream>
#include<vector>
using namespace std;
int map[9][9];
vector<pair<int, int>> emptyBlock;
vector<int> check(int y, int x) {
	vector<int> v;
	// 숫자들을 하나씩 대조해본다.
	for (int i = 1; i < 10; i++) {
		bool flag = false;
		for (int j = 0; j < 9; j++) {
			// 같은 행에 숫자들을 검사
			if (map[y][j] == i) {
				flag = true;
				break;
			}
			// 같은 열에 숫자들을 검사
			if (map[j][x] == i) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		// 같은 블락에 있는 숫자들을 검사
		int firstY = (y / 3) * 3;
		int firstX = (x / 3) * 3;
		for (int j = firstY; j < firstY + 3; j++) {
			for (int k = firstX; k < firstX + 3; k++) {
				if (map[j][k] == i) {
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			continue;
		// 중복되는게 하나도 없으면 v에 삽입
		v.push_back(i);
	}
	return v;
}
bool solve(int it) {
	// 스도쿠 문제를 해결했다면 return true;
	if (it == emptyBlock.size())
		return true;
	// 다음 0인 칸을 찾는다.
	int y = emptyBlock[it].first;
	int x = emptyBlock[it].second;
	// 해당 칸에 들어갈 수 있는 숫자들을 찾는다.
	vector<int> valid = check(y, x);
	// 해당 칸에 들어갈 수 있는 수가 없다면 그 전 과정이 잘못됨
	if (valid.empty())
		return false;
	// 들어갈 수 있는 수들을 하나씩 대입
	for (int k = 0; k < valid.size(); k++) {
		map[y][x] = valid[k];
		if (solve(it + 1) == true)
			return true;
		map[y][x] = 0;
	}
	// 이전 단계의 숫자 선택이 잘못된 경우
	return false;
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				emptyBlock.push_back(make_pair(i, j));
		}
	}
	solve(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << map[i][j] << ' ';
		cout << endl;
	}

}
