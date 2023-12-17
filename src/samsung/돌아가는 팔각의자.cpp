#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>vec(4,vector<int>(8,0));
int k,n,d; // 회전 횟수, 
bool visited[4];
bool can[4];
void turn(int a,int dir){ 
    visited[a] = true;
    if(a>0){
        if(vec[a-1][2] != vec[a][6] && !visited[a-1]){
            turn(a-1,dir*(-1));
        }
    }
    if(a<3){
        if(vec[a+1][6] != vec[a][2] && !visited[a+1]){
            turn(a+1,dir*(-1));
        }
    }
    if(dir == 1){
        int temp = vec[a][7];
        for(int i=7;i>0;i--){
            vec[a][i] = vec[a][i-1];
        }
        vec[a][0] = temp;
    }
    else if(dir == -1){
        int temp = vec[a][0];
        for(int i=0;i<7;i++){
            vec[a][i] = vec[a][i+1];
        }
        vec[a][7] = temp;
    }
}
int main(){
    string str;
    for(int i=0;i<4;i++){
        getline(cin,str);
        for(int t=0;t<8;t++){
            vec[i][t] = (str[t]-'0');
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        memset(visited,false,sizeof(bool)*4);
        scanf("%d %d",&n,&d);
        turn(n-1,d);
    }
    
    int sum = 0;
    int cnt = 1;
    for(int i=0;i<4;i++){
        sum+=(cnt * (vec[i][0]));
        cnt*=2;
    }
    printf("%d",sum);
}