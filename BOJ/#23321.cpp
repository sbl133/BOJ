#include<iostream>
#include<vector>
using namespace std;
vector<string> photo;
int main() {
	string input;
	for (int i = 0; i < 5; i++) {
		cin >> input;
		photo.push_back(input);
	}
	for (int i = 0; i < photo[0].size(); i++) {
		// 도약 준비면 도약중으로 바꾸기
		if (photo[0][i] == '.' && photo[1][i] == 'o') {
			photo[0][i] = 'o';
			photo[1][i] = 'w';
			photo[2][i] = 'l';
			photo[3][i] = 'n';
			photo[4][i] = '.';
		}
		// 도약 중이면 도약 준비로 바꾸기
		else if (photo[0][i] == 'o' && photo[1][i] == 'w') {
			photo[0][i] = '.';
			photo[1][i] = 'o';
			photo[2][i] = 'm';
			photo[3][i] = 'l';
			photo[4][i] = 'n';
		}
		// 착석은 그대로
		else if (photo[0][i] == '.' && photo[1][i] == '.') {
			continue;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << photo[i] << endl;
}
