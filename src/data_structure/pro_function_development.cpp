#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> result;
    double temp1,temp2,temp3;
    int len=progresses.size();
    for(int i=0;i<len;i++){
        temp1 = progresses[i];
        temp2 = speeds[i];
        temp3 = (100-temp1)/temp2;
        result.push_back(ceil(temp3));
    }
    int count = 1;
    int max = 0;
    for(int i=0;i<len;i++){
        if(i == len-1){
            answer.push_back(count);
            return answer;
        }
        if(result[i] <= 0){
            count++;
        }
        if(result[i] >= result[i+1]){
            count++;
            result[i+1] = result[i];
        }
        else{
            max = result[i];
            answer.push_back(count);
            for(int t=i+1;t<len;t++){
                result[t] -= max;
            }
            count = 1;
        }
    }
}