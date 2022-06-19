#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, k;
// vector<물건의 가치, 물거의 무게>
vector<pair<int, int>> items;
// 메모이제이션을 위한 cache
int cache[100][100001];
int packing(int item, int weight) {
	// 전체 물건 순회를 완료했으면 return 0; 
	if (item == n)return 0;
	int& ret = cache[item][weight];
	if (ret != -1)return ret;
	ret = 0;
	// 현재 물건을 담을수 있으면 담아본다.
	if (weight + items[item].second <= k)
		ret = items[item].first + packing(item + 1, weight + items[item].second);
	// 현재 물건을 안담았을 경우도 고려한다.
	ret = max(ret, packing(item + 1, weight));
	return ret;
}
int main() {
	cin >> n >> k;
	int w, v;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		items.push_back(make_pair(v, w));
	}
	cout << packing(0, 0) << endl;
}
