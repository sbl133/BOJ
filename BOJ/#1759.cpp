#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int L, C;
vector<char> vowels = { 'a','e','i','o','u' };
vector<char> v;
// 완성된 암호가 주어진 조건(모음, 자음)을 만족하는 검사
bool validate(vector<char> current) {
	int vow = 0, con = 0;
	for (int i = 0; i < current.size(); i++) {
		if (vowels.end() == find(vowels.begin(), vowels.end(), current[i]))
			con++;
		else
			vow++;
	}
	if (vow >= 1 && con >= 2)
		return true;
	return false;
}
// 주어진 문자들로 만들 수 있는 경우의 수 조합
void combination(vector<char> current, int index) {
	// 다 만들었을 경우
	if (current.size() == L) {
		// 유효성 검사해서 통과하면 출력
		if (validate(current)) {
			for (int i = 0; i < current.size(); i++)
				cout << current[i];
			cout << endl;
		}
		return;
	}
	// 경우의 수 조합
	for (int i = index; i < v.size(); i++) {
		current.push_back(v[i]);
		combination(current, i + 1);
		current.pop_back();
	}
}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	// 주어진 문자들을 알파벳 순으로 정렬
	sort(v.begin(), v.end());
	vector<char> current;
	combination(current, 0);
}
