#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,temp,pl,mi,mul,sum;
vector<int> vec;
vector<char> choose;
char arr[12];
priority_queue<int> pq;
priority_queue<int,vector<int>,greater<int>> pq2;
bool visited[12];
void dfs(int len){
    if(len == n-1){
        sum = vec[0];
        for(int i=0;i<n-1;i++){
            if(arr[i] == '+'){
                sum += vec[i+1];
            }
            else if(arr[i] == '-'){
                sum -= vec[i+1];
            }
            else if(arr[i] == '*'){
                sum *= vec[i+1];
            }
        }
        pq.push(sum);
        pq2.push(sum);
        return;
    }
    for(int i=0;i<choose.size();i++){
        if(!visited[i]){
            visited[i] = true;
            arr[len] = choose[i];
            dfs(len+1);
            visited[i] = false;
        }
    }

}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    scanf("%d %d %d",&pl,&mi,&mul);
    for(int i=0;i<pl;i++){
        choose.push_back('+');
    }
    for(int i=0;i<mi;i++){
        choose.push_back('-');
    }
    for(int i=0;i<mul;i++){
        choose.push_back('*');
    }
    dfs(0);
    printf("%d %d",pq2.top(),pq.top());
}