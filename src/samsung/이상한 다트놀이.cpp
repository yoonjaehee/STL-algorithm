#include <iostream>
#include <vector>
using namespace std;
int n,m,q;
vector<vector<int>> order; // 명령
void dfs(int start,vector<vector<vector<int>>> vec){
    if(start == q){
        int sum = 0;
        for(int i=0;i<=n;i++){
            for(int t=0;t<m;t++){
                if(vec[i][t][0] !=0){
                    sum+=vec[i][t][0];
                }
            }
        }
        printf("%d",sum);
        return;
    }
    vector<vector<vector<int>>> vec2 = vec; 
    if(order[start][1] == 0){ // 시계방향
        for(int i=order[start][0];i<=n;i+=order[start][0]){
            for(int t=0;t<m;t++){
                if(t-order[start][2] < 0){
                    vec[i][t][0] = (vec2[i][n+(t-order[start][2])][0]);
                }
                else{
                    vec[i][t][0] = (vec2[i][t-order[start][2]][0]);
                }
            }
        }
    }
    else if(order[start][1] == 1){ // 반시계방향
        for(int i=order[start][0];i<=n;i+=order[start][0]){
            for(int t=0;t<m;t++){
                if(t+order[start][2] >= n){
                    vec[i][t][0] = (vec2[i][(t+order[start][2])-(n)][0]);
                }
                else{
                    vec[i][t][0] = (vec2[i][t+order[start][2]][0]);
                }
            }
        }
    }
    vec2 = vec;
    for(int i=1;i<=n;i++){
        for(int t=0;t<m;t++){
            if(vec2[i][t][0] == 0){
                continue;
            }
            // 위아래 비교
            if(i == 1){
                if(vec2[i][t][0] == vec2[i+1][t][0]){
                    vec[i][t][0] = 0;
                    vec[i+1][t][0] = 0;
                }
            }
            else if(i == n){
                if(vec2[i][t][0] == vec2[i-1][t][0]){
                    vec[i][t][0] = 0;
                    vec[i-1][t][0] = 0;
                }
            }
            else{
                if(vec2[i][t][0] == vec2[i-1][t][0]){
                    vec[i][t][0] = 0;
                    vec[i-1][t][0] = 0;
                }
                if(vec2[i][t][0] == vec2[i+1][t][0]){
                    vec[i][t][0] = 0;
                    vec[i+1][t][0] = 0;
                }
            }
            if(t == 0){
                if(vec2[i][t][0] == vec2[i][m-1][0]){
                    vec[i][t][0] = 0;
                    vec[i][m-1][0] = 0;
                }
                if(vec2[i][t][0] == vec2[i][t+1][0]){
                    vec[i][t][0] = 0;
                    vec[i][t+1][0] = 0;
                }
            }
            else if(t == m-1){
                if(vec2[i][t][0] == vec2[i][0][0]){
                    vec[i][t][0] = 0;
                    vec[i][0][0] = 0;
                }
                if(vec2[i][t][0] == vec2[i][t-1][0]){
                    vec[i][t][0] = 0;
                    vec[i][t-1][0] = 0;
                }
            }
            else{
                if(vec2[i][t][0] == vec2[i][t+1][0]){
                    vec[i][t][0] = 0;
                    vec[i][t+1][0] = 0;
                }
                if(vec2[i][t][0] == vec2[i][t-1][0]){
                    vec[i][t][0] = 0;
                    vec[i][t-1][0] = 0;
                }
            }
        }
    }
    /*for(int i=0;i<vec.size();i++){
        for(int t=0;t<vec[i].size();t++){
            printf("%d ",vec[i][t][0]);
        }
        printf("\n");
    }
    */
    dfs(start+1,vec);
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    vector<vector<vector<int>>>arr2(n+1,vector<vector<int>>(m,vector<int>(3,0)));
    for(int t=0;t<m;t++){
        vector<int> temp;
        temp.push_back(0);
        temp.push_back(0);
        temp.push_back(0);
        arr2[0][t] = temp;
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            int a;
            vector<int> temp;
            scanf("%d",&a);
            temp.push_back(a);
            temp.push_back(i+1);
            temp.push_back(t+1);
            arr2[i+1][t] = temp;
        }
    }
    for(int i=0;i<q;i++){
        vector<int> temp2;
        int x,d,k;
        scanf("%d %d %d",&x,&d,&k);
        temp2.push_back(x);
        temp2.push_back(d);
        temp2.push_back(k);
        order.push_back(temp2);
    }
    dfs(0,arr2);
}