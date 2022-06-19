#include<iostream>
#include<vector>
using namespace std;
const int INF = 987654321;
// 집과 치킨집의 좌표를 저장하는 vector home, store
vector<pair<int, int>>home;
vector<pair<int, int>>store;
bool visited[13] = { false, };
int n, m;
// homeIdx번째 집과 storeIdx번째 가게사의 거리를 반환
int calcDistance(int homeIdx, int storeIdx) {
	int r1 = home[homeIdx].first, c1 = home[homeIdx].second;
	int r2 = store[storeIdx].first, c2 = store[storeIdx].second;
	return (abs(r1 - r2) + abs(c1 - c2));
}
// iter번째 남겨둘 m개의 치킨집을 고르고, 다 골랐으면 도시 치킨거리 계산
int chickenDistance(int iter, int select) {
	int ret = 0;
	// m개의 치킨집을 다 골랐으면 도시 치킨거리 계산
	if (select == m) {
		for (int i = 0; i < home.size(); i++) {
			int homeDistance=INF;
			for (int j = 0; j < store.size(); j++) 
				if (visited[j]) 
					homeDistance = min(homeDistance, calcDistance(i, j));
			ret += homeDistance;
		}
		return ret;
	}
	// m개 치킨집을 고르기전에 더 이상 순회할 치킨집이 없으면 return INF;
	if (iter == store.size()) return INF;
	// 현재 치킨집을 방문한 경우
	visited[iter] = true;
	ret = chickenDistance(iter + 1, select + 1);
	// 현재 치킨집을 방문하지 않은 경우
	visited[iter] = false;
	// 방문 하거나 안한경우 둘 중 작은값 선택
	ret = min(ret, chickenDistance(iter + 1, select));
	return ret;
}
int main() {
	cin >> n >> m;
	int place;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> place;
			if (place == 1)
				home.push_back(make_pair(i, j));
			else if (place == 2)
				store.push_back(make_pair(i, j));
		}
	cout << chickenDistance(0, 0) << endl;
}
