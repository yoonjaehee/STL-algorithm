#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n;
char arr[51][51];
vector<string> vec;
priority_queue<int> pq;
int px[2] = {1,0};
int py[2] = {0,1};
int ty[4] = {1,-1,0,0};
int tx[4] = {0,0,1,-1};
int cnt;
bool visited[51][51];
void dfs(int starty,int startx){
    visited[starty][startx] = true;
    for(int m=0;m<4;m++){
        int temy = ty[m] + starty;
        int temx = tx[m] + startx;
        if(!visited[temy][temx] && temy>=0 && temy<n && temx>=0 && temx<n){
            if(arr[starty][startx] == arr[temy][temx]){
                visited[temy][temx] = true;
                cnt++;
                dfs(temy,temx);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    string str;
    char temp;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,str);
        for(int t=0;t<n;t++){ 
            arr[i][t] = str[t];
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            for(int p=0;p<2;p++){ //바꾸기
                int nx = px[p] + t;
                int ny = py[p] + i;
                if(arr[ny][nx] != arr[i][t] && ny>=0 && ny<n && nx>=0 && nx<n){
                    temp = arr[ny][nx];
                    arr[ny][nx] = arr[i][t];
                    arr[i][t] = temp;
                    for(int q=0;q<n;q++){
                        memset(visited[q],false,sizeof(bool)*n);
                    }
                    for(int u=0;u<n;u++){
                        for(int g=0;g<n;g++){
                            if(!visited[u][g]){
                                cnt = 1;
                                dfs(u,g);
                                pq.push(cnt);
                            }
                        }
                    }
                    temp = arr[ny][nx];
                    arr[ny][nx] = arr[i][t];
                    arr[i][t] = temp;
                }
            }
        }
    }
    printf("%d",pq.top());
}