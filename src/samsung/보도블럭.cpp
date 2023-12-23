#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,dis;
bool already[101][101];
int arr[101][101];
int cnt = 0;
int cnt2;
void confirm2(int start){ // 세로 검사
    bool can = true;
    cnt2 = 1;
    int cur = arr[0][start];
    for(int i=1;i<n;i++){
        cur = arr[i-1][start];
        if(already[i][start]){
            cnt2=0;
            continue;
        }
        if(arr[i][start] > cur){
            if(arr[i][start] - cur > 1){
                can = false;
                return;
            }
            if(cnt2 < dis){
                can = false;
                return;
            }
            if(dis == 1 && already[i-1][start]){
                can = false;
                return;
            }
            cnt2=1;
        }
        else if(arr[i][start] == cur){
            cnt2++;
        }
        else{
            already[i][start] = true;
            if(cur - arr[i][start]> 1){
                can = false;
                return;
            }
            if(i + dis > n){
                can = false;
                return;
            }
            for(int t=1;t<dis;t++){
                if(arr[i+t][start] != arr[i][start]){
                    can = false;
                    return;
                }
                else{
                    if(i+t == n-1){
                        cnt++;
                        return;
                    }
                    else{
                        already[i+t][start] = true;
                        cnt2 = 0;
                    }
                }
            }
        }
    }
    if(can){
        cnt++;
    }
}
void confirm1(int start){ // 가로 검사
    bool can = true;
    cnt2 = 1;
    int cur = arr[start][0];
    for(int i=1;i<n;i++){ 
        cur = arr[start][i-1];
        if(already[start][i]){
            cnt2=0;
            continue;
        }
        if(arr[start][i] > cur){ // 전것보다 클때
            if(arr[start][i] - cur > 1){
                can = false;
                return;
            }
            if(cnt2 < dis){
                can = false;
                return;
            }
            if(dis == 1 && already[start][i-1]){
                can = false;
                return;
            }
            cnt2=1;
        }
        else if(arr[start][i] == cur){
            cnt2++;
        }
        else{ // 전것보다 작을때
            if(cur - arr[start][i] > 1){
                can = false;
                return;
            }
            if(i + dis > n){
                can = false;
                return;
            }
            already[start][i] = true;
            for(int t=1;t<dis;t++){
                if(arr[start][i+t] != arr[start][i]){
                    can = false;
                    return;
                }
                else{
                    if(i+t == n-1){
                        cnt++;
                        return;
                    }
                    else{
                        already[start][i+t] = true;
                        cnt2 = 0;
                    }
                }
            }
        }
    }
    if(can){
        cnt++;
    }
}
int main(){
    scanf("%d %d",&n,&dis);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    for(int i=0;i<n;i++){
        confirm1(i);
    }
    for(int i=0;i<n;i++){
        memset(already[i],false,sizeof(bool)*n);
    }
    for(int i=0;i<n;i++){
        confirm2(i);
    }
    printf("%d",cnt);
}