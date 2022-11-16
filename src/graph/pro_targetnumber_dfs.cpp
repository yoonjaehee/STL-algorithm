#include <string>
#include <vector>

using namespace std;
int len;
int count = 0;
vector<int> vec;
void dfs(int start,int end,int number,int t){
    if(start == end && t == len){
        count++;
    }
    else if(t != len){
        dfs(start+number,end,vec[t+1],t+1);
        dfs(start-number,end,vec[t+1],t+1);   
    }
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    len=numbers.size();
    vec = numbers;
    dfs(0,target,numbers[0],0);
    answer = count;
    return answer;
}