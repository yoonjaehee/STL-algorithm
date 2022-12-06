#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n,mx,temp;
int dfs(vector<vector<int>> tem){ 
    vector<vector<int>> temp;
    temp = tem;
    //위로 이동
    for(int i=1;i<n;i++){
        for(int t=0;t<n;t++){
            if(temp[i][t] == temp[i-1][t]){ // 위에 숫자가 똑같을때 : 합치고 밀기
                temp[i][t] = 0;
                temp[i-1][t]*=2;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int t=0;t<n;t++){
            for(int p=i;p>0;p--){
                if(temp[p-1][t] == 0){
                    temp[p-1][t] = temp[p][t];
                }
            }
        }
    }
    dfs(temp);
    temp = tem;
    //아래로 이동
    for(int i=n-1;i>0;i++){
        for(int t=0;t<n;t++){
            if(temp[i-1][t] == temp[i][t]){ // 위에 숫자가 똑같을때 : 합치고 밀기
                temp[i-1][t] = 0;
                temp[i][t]*=2;
            }
        }
    }
    for(int i=n-1;i>0;i++){
        for(int t=0;t<n;t++){
            for(int p=i;p<n;p++){
                if(temp[p+1][t] == 0){
                    temp[p+1][t] = temp[p][t];
                    temp[p][t]=0;
                }
            }
        }
    }
    dfs(temp);
    temp = tem;
    //오른쪽으로 밀음
    for(int i=0;i<n;i++){
        for(int t=0;t<n-1;t++){
            if(temp[i][t] == temp[i][t+1]){ // 위에 숫자가 똑같을때 : 합치고 밀기
                temp[i][t] = 0;
                temp[i][t+1]*=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n-1;t++){
            for(int p=t;p<n;p++){
                if(temp[i][p] == 0){
                    temp[i][p] = temp[i][t];
                }
            }
        }
    }
    dfs(temp);
    temp = tem;
    //왼쪽으로 밀음

}
int main(){
    scanf("%d",&n);
    vector<vector<int>> vec;
    mx = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&temp);
            vec[i].push_back(temp);
        }
    }
    dfs(vec);
}