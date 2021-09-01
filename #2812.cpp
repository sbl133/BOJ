#include<iostream>
#include<string>
#include<queue>
using namespace std;
string input;
deque<char> q;
int N, K;
void delWithBig() {
	// 문자열 input를 순회하면서
	for (int i = 0; i < input.length(); i++) {
		// 삭제할게 있는데, 덱에 있는것보다 input[i]가 크면 덱에 요소 삭제
		while (K && !q.empty() && q.back() < input[i]) {
			q.pop_back();
			K--;
		}
		q.push_back(input[i]);
	}
	// 삭제할게 남았으면 덱에서 그 만큼 덜 출력 
	for (int i = 0; i < q.size() - K; i++)
		cout << q[i];
}
int main() {
	cin >> N >> K;
	cin >> input;
	delWithBig();
}
