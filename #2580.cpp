#include<iostream>
#include<vector>
using namespace std;
int map[9][9];
vector<int> check(int y, int x) {
	vector<int> v;
	for (int i = 1; i < 10; i++) {
		bool flag = false;
		for (int j = 0; j < 9; j++) {
			if (map[y][j] == i) {
				flag = true;
				break;
			}
			if (map[j][x] == i) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
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
		v.push_back(i);
	}
	return v;
}
bool solve() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				vector<int> valid = check(i, j);
				if (valid.empty())
					return false;
				for (int k = 0; k < valid.size(); k++) {
					map[i][j] = valid[k];
					if (solve() == true)
						return true;
					map[i][j] = 0;
				}
			}
		}
	}
	return true;
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> map[i][j];
	}
	solve();
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << map[i][j] << ' ';
		cout << endl;
	}

}
