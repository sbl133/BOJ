#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[100000];
void bfs(int start, vector<bool>& discovered) {
	queue<int> q;
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int a, b;
	for (int i = 1; i <= m; i++) {
		// 해당지점의 간선 없이 그래프 형성
		if (i == k) {
			cin >> a >> b;
			continue;
		}
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	long long visited = 0;
	vector<bool> discovered(n, false);
	// 그래프를 bfs탐색
	bfs(0, discovered);
	for (int i = 0; i < n; i++)
		if (discovered[i] == true)
			visited++;
	// 총 비용 = 방문한 정점의 갯수 * 방문못한 정점의 갯수
	cout << visited * (n - visited) << endl;
}
