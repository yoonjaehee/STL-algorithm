#include <iostream>
#include <vector>
using namespace std;
int order[11]; // 실제 가야할것
int arr[34]; // 다음위치
int score[34]; // 점수
int turn[34]; // 파란색 화살표 있는 전환 지점
bool visited[34];
int res = 0;
int horse[4]= {0,0,0,0};
void dfs(int start,int sum){
    if(start == 10){
        if(res < sum){
            res = sum;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int prev = horse[i];
        int cur = prev;
        int move = order[start];
        if(turn[cur] > 0){ // 전환점 도달해있을때
            cur = turn[cur];
            move--;
        }
        while(move > 0){
            cur = arr[cur];
            move--;
        }
        if(cur != 21 && visited[cur]){
            continue;
        }
        visited[prev] = false;
        visited[cur] = true;
        horse[i] = cur;
        dfs(start+1,sum+score[cur]);
        horse[i] = prev;
        visited[prev] = true;
        visited[cur] = false;
    }
}
int main(){
    for(int i=0;i<33;i++){
        arr[i] = i+1;
    }
    arr[21] = 21; 
    arr[27] = 20;
    arr[30] = 25;
    arr[32] = 25;
    turn[5] = 22; 
    turn[10] = 31;
    turn[15] = 28;
    for(int i=0;i<21;i++){
        score[i] = 2 * i;
    }
    score[22] = 13; // 10으로 빠짐
    score[23] = 16;
    score[24] = 19;
    score[25] = 25;
    score[26] = 30; 
    score[27] = 35;
    score[28] = 28; // 
    score[29] = 27;
    score[30] = 26;
    score[31] = 22;
    score[32] = 24;
    for(int i=0;i<10;i++){
        scanf("%d",&order[i]);
    }
    dfs(0,0);
    printf("%d",res);
}