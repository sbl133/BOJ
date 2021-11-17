#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> can;
int n, k;
int eat, day;
void greedy() {
	int i;
	sort(can.begin(), can.end());
	for (i = k; i < n; i++) {
		if (can[i] != can[i - k]) {
			eat += can[i] - can[i - k];
			can[i] = can[i - k];
			day++;
			break;
		}
	}
	if (i == n)return;
	else greedy();
}
int main() {
	cin >> n >> k;
	eat = day = 0;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		can.push_back(tmp);
	}
	greedy();
	cout << eat << " " << day;
}
