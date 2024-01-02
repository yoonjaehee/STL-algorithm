#include <iostream>
#include <vector>
using namespace std;
int n,y,x,d,g;
bool arr[101][101];
vector<int> vec;
vector<int> temp;
int tmpdir;
void dfs(int sty,int stx,int cnt){
    if(cnt == 0){
        return;
    }
    temp.clear();
        for(int i=vec.size()-1;i>=0;i--){
            tmpdir = (vec[i] + 1) % 4;
            if(tmpdir == 0){ // 
                stx+=1;
            }
            else if(tmpdir == 1){
                sty-=1;
            }
            else if(tmpdir == 2){
                stx-=1;
            }
            else if(tmpdir == 3){
                sty+=1;
            }
            arr[sty][stx] = true;
            temp.push_back(tmpdir);
        }
        for(int i=0;i<temp.size();i++){
            vec.push_back(temp[i]);
        }
    dfs(sty,stx,cnt-1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        vec.clear();
        scanf("%d %d %d %d",&y,&x,&d,&g);
        arr[y][x] = true;
        vec.push_back(d);
        if(d == 0){
            x+=1;
        }
        else if(d== 1){
            y-=1;
        }
        else if(d==2){
            x-=1;
        }
        else{
            y+=1;
        }
        arr[y][x] = true;
        dfs(y,x,g);       
    }
    int ans = 0;
    for(int i=0;i<=100;i++){
        for(int t=0;t<=100;t++){
            if(arr[i][t] && arr[i+1][t] && arr[i+1][t+1] && arr[i][t+1]){
                ans++;
            }
        }
    }
    printf("%d",ans);
}