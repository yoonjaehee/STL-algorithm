#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int temp;
    int len = scoville.size();
    int put;
    sort(scoville.begin(),scoville.end(),greater());
    for(int i=0;i<len;i++){
        temp = scoville.size();
        if((temp == 1) && (scoville[0] < K)){
            answer = -1;
            return answer;
        }
        if(temp == 1){
            answer = len-temp;
            return answer;
        }
        put=scoville[temp-2] * 2 + scoville[temp-1];
        scoville[temp-2] = put;
        scoville.pop_back();
        sort(scoville.begin(),scoville.end(),greater());
        if(scoville[temp-2]>K){
            answer = len - scoville.size();
            return answer;
        }
    }
    answer=len - scoville.size();
    return answer;
}