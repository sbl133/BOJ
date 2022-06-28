#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(long long num){
    if(num == 1 || num == 0)
        return false;
    int sqr = sqrt(num);
    sqr++;
    for(int i = 2; i < sqr; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> changeNum;
    while(n>0){
        changeNum.push_back(n%k);
        n = n/k;
    }
    long long unitNum = 0;
    int digit = 0;
    for(int i=0; i<changeNum.size(); i++){
        unitNum = unitNum + (changeNum[i] * pow(10, digit));
        digit++;
        if (changeNum[i] == 0 || i == changeNum.size()-1){
            if(isPrime(unitNum))
                answer++;
            unitNum=0;
            digit=0;
        }
    }
    return answer;
}