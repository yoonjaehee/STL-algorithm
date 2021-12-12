#include <iostream>
#include <vector>
using namespace std;
int num,rows,cols;
vector<vector<bool>> visited;
vector<vector<bool>> arr;
vector<int> bug_count;
int px[4] = {1,-1,0,0};
int py[4] = {0,0,1,-1};
void dfs(int x,int y){
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + px[i];
        int ny = y + py[i];
        if(nx>=0 && nx<rows && ny<cols && ny>=0){
            if(arr[nx][ny] && !visited[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
}
int main(){
    int count,x,y;
    scanf("%d", &count);
    for(int i=0;i<count;i++){
        scanf("%d %d %d", &rows, &cols, &num);
        visited = vector<vector<bool>>(rows, vector<bool>(cols,false));
        arr = vector<vector<bool>>(rows, vector<bool>(cols,false));
        int bug = 0;
        for(int t=0;t<num;t++){
            scanf("%d %d", &x,&y);
            arr[x][y]=true;
        }
        for(int p=0;p<rows;p++){
            for(int q=0;q<cols;q++){
                if(arr[p][q] && !visited[p][q]){
                    bug++;
                    dfs(p,q);
                }
            }
        }
        bug_count.push_back(bug);
    }
    for(int i=0;i<count;i++){
        printf("%d\n", bug_count[i]);
    }
}