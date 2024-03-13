#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,k,c;
int res = 0;
int arr[21][21];
int tmp[21][21];
int cal[21][21];
int dely,delx;
int dy[4]={1,1,-1,-1};
int dx[4]={1,-1,1,-1};
int groy[4] = {1,-1,0,0};
int grox[4] = {0,0,1,-1};
int consist[21][21]={99999,};
int big;
void grow(){
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(arr[i][t]>0){
                int cnt = 0;
                int cnt2 = 0;
                int cnt3 = 0;
                for(int p=0;p<4;p++){
                    int ny = i+groy[p];
                    int nx = t+grox[p];
                    if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                        if(arr[ny][nx] >= 1){
                            cnt+=1;
                        }
                        if(arr[ny][nx] < 0){
                            cnt2+=1;
                        }
                    }
                    else{
                        cnt3+=1;
                    }
                }
                arr[i][t] = arr[i][t] + cnt;
                tmp[i][t] = 4-cnt-cnt2-cnt3;
            }
        }
    }
}
void copy(){
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(tmp[i][t] >= 1 && tmp[i][t] != 4){
                for(int p=0;p<4;p++){
                    int ny = i+groy[p];
                    int nx = t+grox[p];
                    if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                        if(arr[i][t] > 0 && arr[ny][nx] == 0){
                            cal[ny][nx] += (arr[i][t]/tmp[i][t]);
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(cal[i][t] != 0){
                arr[i][t] += cal[i][t];
            }
        }
    }
}
void choose(){
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(arr[i][t] >= 1){
                vector<bool> can(4,true);
                int sum = arr[i][t];
                for(int p=1;p<=k;p++){
                    for(int q=0;q<4;q++){
                        int ny = i+(p*dy[q]);
                        int nx = t+(p*dx[q]);
                        if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                            if((arr[ny][nx] >0) && (can[q])){
                                sum += arr[ny][nx];
                            }
                            else{
                                can[q] = false;
                            }
                        }
                    }
                }
                if(big < sum){
                    big = sum;
                    dely = i;
                    delx = t;
                }
            } 
        }
    }
}
void remove(){
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(arr[i][t] == -2){
                if(consist[i][t]==1){
                    consist[i][t] = 500000;
                    arr[i][t] = 0;
                }
                else if(consist[i][t] > 1){
                    consist[i][t]-=1;
                }
            }
        }
    }
    vector<bool> can(4,true);
    arr[dely][delx] = -2;
    consist[dely][delx] = c;
    for(int i=1;i<=k;i++){
        for(int t=0;t<4;t++){
            int ny = dely + i*dy[t];
            int nx = delx + i*dx[t];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(arr[ny][nx] > 0 && can[t]){
                    arr[ny][nx] = -2;
                    consist[ny][nx] = c;
                }
                else if(arr[ny][nx] == 0){
                    arr[ny][nx] = -2;
                    consist[ny][nx] = c;
                    can[t] = false;
                }
                else{
                    can[t] = false;
                }
            }
        }
    }
}
void dfs(int start){
    big = 0;
    if(start == m){
        return;
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            cal[i][t] = 0;
            tmp[i][t] = 0;
        }
    }
    grow();
    copy();
    choose(); // 제초제 고르기
    remove(); // 제초제 고르고, 제초제 남아있는거 없애기 
    res+=big;
    printf("\n");
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            printf("%d ",arr[i][t]);
        }
        printf("\n");
    }
    
    dfs(start+1);
}
int main(){
    scanf("%d %d %d %d",&n,&m,&k,&c);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
            consist[i][t] = 500000;
        }
    }
    dfs(0);
    printf("%d",res);
}