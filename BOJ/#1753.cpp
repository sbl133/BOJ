// 입출력이 많으므로 iostream대신 cstdio를 사용
#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
// 충분히 큰 값 INF 정의
const int INF = 987654321;
// 정점과 간선의 갯수
int v, e;
// 인접행렬에 (연결된 정점 번호, 간선 가중치)쌍을 저장
vector<pair<int, int>> adj[20001];
// src에서의 각 정점의 최단거리를 저장하는 배열 dist
vector<int> dist;
void dijkstra(int src) {
	dist.assign(v, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		// 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금것을 무시
		if (dist[here] < cost)continue;
		// 인접한 정점 모두 검사
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = dist[here] + adj[here][i].second;
			// 더 짧은 경로를 발견하면, dist갱신하고 pq에 삽입
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
}
int main() {
	int src;
	scanf("%d %d", &v, &e);
	scanf("%d", &src);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(make_pair(v - 1, w));
	}
	dijkstra(src - 1);
	for (int i = 0; i < v; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}
