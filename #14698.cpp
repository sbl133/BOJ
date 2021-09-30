#include<cstdio>
#include<queue>
using namespace std;
typedef long long Long;
// 1000000007로 나눈 나머지를 출력
const Long MOD = 1000000007;
int slime(priority_queue<Long>& pq) {
	int ret = 1;
	// 마지막 슬라임이 남을 때 까지
	// 현재 가장 작은 슬라임 두개를 합치고 다시 우선순위큐에 넣어서 정렬시킨다.
	while (pq.size() > 1) {
		Long a = -pq.top();
		pq.pop();
		Long b = -pq.top();
		pq.pop();
		Long combine = a * b;
		// combine과 ret를 그냥 곱하면 오버플로우가 날 수 있어 combine먼저 MOD로 나눠주고
		// ret결과 값에 다시 MOD로 나눈 나머지를 ret에 저정한다.
		ret = combine % MOD * ret % MOD;
		pq.push(-combine);
	}
	return ret;
}
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int n;
		Long tmp;
		scanf("%d", &n);
		priority_queue<Long> pq;
		if (pq.size() == 1)
			printf("1\n");
		else {
			for (int i = 0; i < n; i++) {
				scanf("%lld", &tmp);
				pq.push(-tmp);
			}
			printf("%d\n", slime(pq));
		}
	}
}
