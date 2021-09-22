#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1001;
int n, edge, start;
vector<int> adj[MAXN];
bool visited[MAXN];
void DFS(int curPos) {
	if (visited[curPos])
		return;
	else {
		visited[curPos] = true;
		cout << curPos << " ";
	}
	for (int i = 0; i < adj[curPos].size(); i++)
		DFS(adj[curPos][i]);
}
void BFS(int startPos) {
	queue<int> q;
	visited[startPos] = true;
	q.push(startPos);
	cout << startPos << " ";
	while (!q.empty()) {
		int curPos = q.front();
		q.pop();
		for (int i = 0; i < adj[curPos].size(); i++) {
			if (visited[adj[curPos][i]])
				continue;
			visited[adj[curPos][i]] = true;
			cout << adj[curPos][i] << " ";
			q.push(adj[curPos][i]);
		}
	}
}
int main() {
	cin >> n >> edge >> start;
	int x, y;
	for (int i = 0; i < edge; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	memset(visited, 0, sizeof(visited));
	DFS(start);
	cout << endl;
	memset(visited, 0, sizeof(visited));
	BFS(start);
}
