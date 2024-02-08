#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,q,len;
int arr[128][128];
int py[4] = {1,-1,0,0};
int px[4] = {0,0,1,-1};
bool tomelt[128][128];
vector<int> order;
void change(int y,int x,int moving,vector<vector<int>> confirm){
    if(x%2 == 0){  
        if(y%2 == 0){ // 1사분면
            for(int i=0;i<moving;i++){
                for(int t=0;t<moving;t++){
                    arr[(y*moving) + i][(x*moving) + t] = confirm[(y*moving)+i + moving][(x*moving)+t];
                }
            }
        }
        else{ // 4사분면
            for(int i=0;i<moving;i++){
                for(int t=0;t<moving;t++){
                    arr[(y*moving) + i][(x*moving) + t] = confirm[(y*moving)+i][(x*moving)+t + moving];
                }
            }
        }
    }
    else{
        if(y%2 == 0){ // 2사분면
            for(int i=0;i<moving;i++){
                for(int t=0;t<moving;t++){
                    arr[(y*moving) + i][(x*moving) + t] = confirm[(y*moving)+i][(x*moving)+t - moving];
                }
            }
        }
        else{ // 3사분면
            for(int i=0;i<moving;i++){
                for(int t=0;t<moving;t++){
                    arr[(y*moving) + i][(x*moving) + t] = confirm[(y*moving)+i-moving][(x*moving)+t];
                }
            }
        }
    }
}
void dfs(vector<vector<int>> vec,int cnt){
    if(cnt == q){
        for(int i=0;i<len;i++){
            for(int t=0;t<len;t++){
                arr[i][t] = vec[i][t];
            }
        }
        return;
    }
    bool ischange = false;
    if(order[cnt] == 0){
        ischange = true;
    }
    int len2=1;
    for(int i=0;i<order[cnt]-1;i++){
        len2*=2;
    }
    if(!ischange){
        for(int i=0;i<len/len2;i++){
            for(int t=0;t<len/len2;t++){
                change(i,t,len2,vec);
            }
        }
    }
    else{
        for(int i=0;i<len;i++){
            for(int t=0;t<len;t++){
                arr[i][t] = vec[i][t];
            }
        }
    }
    for(int i=0;i<len;i++){
        memset(tomelt[i],false,sizeof(bool) * len);
    }
    for(int i=0;i<len;i++){
        for(int t=0;t<len;t++){
            int cnt = 0;
            for(int p=0;p<4;p++){
                int ny = i + py[p];
                int nx = t + px[p];
                if(ny >= 0 && nx <len && ny < len && nx >= 0){
                    if(arr[ny][nx] > 0){
                        cnt+=1;
                    }
                }
            }
            if(cnt < 3){
                tomelt[i][t] = true;
            }
        }
    }
    for(int i=0;i<len;i++){
        for(int t=0;t<len;t++){
            if(tomelt[i][t] && (arr[i][t] > 0)){
                arr[i][t] -=1;
            }
            vec[i][t] = arr[i][t];
        }
    }
    dfs(vec,cnt+1);
}
bool visited[128][128];
int res = 0;
int cnt2;
void find(int sty,int stx){
    visited[sty][stx] = true;
    for(int i=0;i<4;i++){
        int ny = sty + py[i];
        int nx = stx + px[i];
        if(ny >= 0 && ny < len && nx >= 0 && nx < len){
            if(arr[ny][nx] > 0 && !visited[ny][nx]){
                cnt2+=1;
                visited[ny][nx] = true;
                find(ny,nx);
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&q);
    len = 1;
    for(int i=0;i<n;i++){
        len*=2;
    } 
    for(int i=0;i<len;i++){
        memset(arr[i],0,sizeof(int) * len);
    }
    int temp;
    vector<vector<int>> vect;
    for(int i=0;i<len;i++){
        vector<int> tmp;
        for(int t=0;t<len;t++){
            scanf("%d",&temp);
            tmp.push_back(temp);
        }
        vect.push_back(tmp);
    }
    for(int i=0;i<q;i++){
        scanf("%d",&temp);
        order.push_back(temp);
    }
    dfs(vect,0);
    int sum = 0;
    for(int i=0;i<len;i++){
        for(int t=0;t<len;t++){
            sum+=arr[i][t];
            if(!visited[i][t] && arr[i][t] > 0){
                cnt2 = 1;
                find(i,t);
            }
            if(cnt2 > res){
                res = cnt2;
            }
            visited[i][t] = true;
        }
    }
    printf("%d\n%d",sum,res);
}