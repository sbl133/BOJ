#include<iostream>
#include<deque>
using namespace std;
int n, m;
int printQueue(deque<int> &q) {
	int result = 0;
	// 입력에서 m번째 index로 주어진 문서의 index를 추적하기 위한 변수
	int traceIndex = m;
	while (!q.empty()) {
		int maximum = 0;
		for (int i = 0; i < q.size(); i++) 
			maximum = max(maximum, q[i]);
		// 현재 큐의 맨앞에 있는 문서의 중요도가 가장 높으면
		if (maximum == q[0]) {
			// 출력 횟수를 +1 하고, 큐에서 빼내고
			result++;
			q.pop_front();
			// 추적하던 문서라면 반복문 종료
			if (traceIndex == 0)
				break;
		}
		// 현재 큐의 맨앞에 있는 문서의 중요도가 낮다면
		else {
			// 큐에서 빼내서 다시 뒤로 집어넣는다.
			int tmp = q[0];
			q.pop_front();
			q.push_back(tmp);
		}
		// 추적 문서의 index 갱신
		traceIndex = (traceIndex - 1 + q.size()) % q.size();
	}
	return result;
}
int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		// index접근을 위해 queue가 아닌 deque로 구현
		deque<int> q;
		int tmp;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			q.push_back(tmp);
		}
		cout << printQueue(q) << endl;
	}
}
