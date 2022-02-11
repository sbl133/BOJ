#include<iostream>
#include<string>
#include<sstream>
#include<deque>
using namespace std;

deque<string> split(string& str, char Delimiter) {

	str = str.substr(1, str.size() - 2);

	deque<string> result;
	
	istringstream iss(str);
	string buffer;
	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);
	}
	return result;
}
void exeFunc(deque<string>& v, string& funcStr) {
	int rNum = 0;
	for (int i = 0; i < funcStr.size(); i++) {
		if (funcStr[i] == 'D') {
			if (rNum % 2 == 0)
				v.pop_front();
			else
				v.pop_back();
		}
		else
			rNum++;
	}
}
int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		string funcStr, numArr;
		int n, rNum = 0, dNum = 0;
		cin >> funcStr;
		cin >> n;
		cin >> numArr;
		for (int i = 0; i < funcStr.size(); i++) {
			if (funcStr[i] == 'R')rNum++;
			else dNum++;
		}
		if (dNum > n) {
			cout << "error" << endl;
			continue;
		}
		deque<string> vStr = split(numArr, ',');
		exeFunc(vStr, funcStr);
		cout << "[";
		if (!vStr.empty()) {
			if (rNum % 2 == 0) {
				for (int i = 0; i < vStr.size() - 1; i++)
					cout << vStr[i] << ",";
				if (!vStr.empty())
					cout << vStr[vStr.size() - 1];
			}
			else {
				for (int i = vStr.size() - 1; i > 0; i--)
					cout << vStr[i] << ",";
				if (!vStr.empty())
					cout << vStr[0];
			}
		}
		cout << "]" << endl;
	}
}
