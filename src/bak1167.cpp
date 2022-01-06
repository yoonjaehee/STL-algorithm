#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> vec[100001];
vector<vector<bool>> visited;
vector<int> cou;
int v,num,temp,temp2;
int max1=0;//count the max array size
void dfs(int x,int y,int count){
    visited[x][vec[x][y].first]=true;
    for(int i=0;i<vec[x].size();i++){
        if(visited[vec[x][i].first][x]){
            continue;
        }
        count+=vec[x][i].second;
        dfs(vec[x][i].first,i,count);
        cou.push_back(count);
    }
}
int main(){
    scanf("%d",&v);
    for(int i=0;i<v;i++){
        scanf("%d", &num);
        if(max1<num){
            max1=num;
        }
        while(1){
            scanf("%d", &temp);
            if(temp == -1){
                break;
            }
            scanf("%d", &temp2);
            vec[num].push_back({temp,temp2});
        }
    }   
    visited = vector<vector<bool>>(max1+1,vector<bool>(max1+1,false));
    for(int i=1;i<=max1;i++){
        for(int t=0;t<vec[i].size();t++){
            if(!visited[i][vec[i][t].first]){
                dfs(i,t,0);
            }
        }
    }
    printf("%d",max(cou.begin(),cou.end()));
}