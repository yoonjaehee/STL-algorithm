#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset<int> arr;
    int temp;
    int len = scoville.size();
    for(int i=0;i<len;i++){
        arr.insert(scoville[i]);
    }
    for(int i=0;i<len;i++){
        temp = arr.size();
        if((temp==1) && (*(arr.begin()) < K)){
            answer = -1;
            return answer;
        }
        if(temp==1){
            answer = len-arr.size();
            return answer;
        }
        arr.insert(*(arr.begin()) + ((*(++arr.begin())*2)));
        arr.erase(arr.begin());
        arr.erase(arr.begin());
        if(*(arr.begin()) >= K){
            answer = len -arr.size();
            return answer;
        }
    }
}