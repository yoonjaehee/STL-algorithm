#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int n,m;
int arr[11];
bool sign[101];
vector<char> vec;
int res2 = INT_MAX;
int res = 0;
void dfs(int num, int cnt,int cur){
    if(cnt == n-1){
        res=max(res,cur);
        res2 = min(res2,cur);
    }
    for(int i=0;i<n-1;i++){
        if(!sign[num]){
            char choose=vec[i];
            sign[i] = true;
            int temp2;
            if(choose == '+'){
                temp2 = arr[num]+cur;
            }
            else if(choose == '-'){
                temp2 = cur-arr[num];
            }
            else if(choose == '*'){
                temp2 = arr[num]*cur;
            }
            else if(choose == '/'){
                temp2 = cur/arr[num];
            }
            dfs(num+1,cnt+1,temp2);
            sign[i]=false;
            }
        }
}
int main(){
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        arr[i] = temp;
    }
    for(int i=0;i<4;i++){
        scanf("%d",&temp);
        for(int t=0;t<temp;t++){
            if(i == 0){
                vec.push_back('+');
            }
            else if(i==1){
                vec.push_back('-');
            }
            else if(i==2){
                vec.push_back('*');
            }
            else if(i==3){
                vec.push_back('/');
            }
        }
    }
    dfs(0,0);
}