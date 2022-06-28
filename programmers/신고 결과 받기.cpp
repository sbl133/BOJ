#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;


int nameToNum(vector<string>& id_list, string name){
    for(int i=0; i<id_list.size(); i++){
        if(name==id_list[i])
            return i;
    }
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

bool isReporting[1000][1000];
int reportedNum[1000];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    memset(isReporting, 0, sizeof(isReporting));
    memset(reportedNum, 0, sizeof(reportedNum));
    vector<int> answer(id_list.size(), 0);
    for(int i=0; i<report.size(); i++){
        vector<string> reportOne = split(report[i], ' ');
        int reporting = nameToNum(id_list, reportOne[0]);
        int reported = nameToNum(id_list, reportOne[1]);
        if(isReporting[reporting][reported]==false){
            isReporting[reporting][reported]=true;
            reportedNum[reported]++;
        }
    }
    for(int i=0; i<id_list.size(); i++){
        if(reportedNum[i]>=k){
            for(int j=0; j<id_list.size(); j++){
                if(isReporting[j][i]==true){
                    answer[j]++;
                }
            }
        }
    }

    return answer;
}