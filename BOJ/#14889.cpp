#include<iostream>
#include<vector>
using namespace std;
int n;
int ability[20][20];
vector<int> teamA;
vector<int> teamB;
bool belong[20] = { false, };
int result = 987654321;
void calc() {
	teamA.clear(); teamB.clear();
	for (int i = 0; i < n; i++) {
		if (belong[i])
			teamA.push_back(i);
		else
			teamB.push_back(i);
	}
	int sumA = 0, sumB = 0;
	for (int i = 0; i < (n / 2); i++) {
		for (int j = 0; j < (n / 2); j++) {
			sumA += ability[teamA[i]][teamA[j]];
			sumB += ability[teamB[i]][teamB[j]];
		}
	}
	result = min(result, abs(sumA - sumB));
}
void solve(int start, int count) {
	if (count == (n / 2))
		calc();
	else 
		for (int i = start; i < n; i++) {
			belong[start] = true;
			solve(i + 1, count + 1);
			belong[start] = false;
		}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> ability[i][j];
	solve(0, 0);
	cout << result;
}
