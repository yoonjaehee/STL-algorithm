#include <iostream>
#include <vector>
using namespace std;
int n,m,temp;
int mx = 0;
int py[4] = {1,-1,0,0};
int px[4] = {0,0,1,-1};
void dfs(vector<vector<int>> tmp,int y,int x,int start,int sum,int tim,vector<pair<int,int>> tmp2,vector<vector<bool>> visited){
   if(start == 4){
    if(mx < sum){
        mx = sum;
    }
    return;
}
    visited[y][x] = true;
    for(int t=0;t<tmp2.size();t++){
        for(int i=0;i<4;i++){
            int ny = y + py[i];
            int nx = x + px[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m){
                if(!visited[ny][nx]){
                    visited[ny][nx] = true;
                    tmp2.push_back({ny,nx});
                    dfs(tmp,ny,nx,start+1,sum + tmp[ny][nx],tim,tmp2,visited);
                }  
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    vector<vector<int>> vec(n,vector<int>(m,0));
    vector<pair<int,int>> vec2;
    vector<vector<bool>> visit(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&temp);
            vec[i][t] = temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            vec2.push_back({i,t});
            dfs(vec,i,t,1,vec[i][t],0,vec2,visit);
            vec2.pop_back();
        }
    }
    printf("%d",mx);
}