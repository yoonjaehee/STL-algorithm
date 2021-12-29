#include <iostream>
#include <vector>
using namespace std;
int num;
int px[4]={0,0,1,-1};
int py[4]={1,-1,0,0};
char squ[101][101]; // store alphabet
vector<vector<bool>> visited; // check visited 
void dfs(int a,int b){
    visited[a][b]=true;
    for(int i=0;i<4;i++){
        int na = a+px[i];
        int nb = b+py[i];
        if(na >= 0 && na<num && nb >=0 && nb<num){
            if((!visited[na][nb]) && (squ[a][b]==squ[na][nb])){
                dfs(na,nb);
            }
        }
    }
}
int main(){
    scanf("%d",&num);
    int count=0;
    visited=vector<vector<bool>>(num,vector<bool>(num,false));
    for(int i=0;i<num;i++){
        for(int t=0;t<num;t++){
            char alpha;
            scanf(" %c",&squ[i][t]);
        }
    }
    for(int i=0;i<num;i++){
        for(int t=0;t<num;t++){
            if(!visited[i][t]){
                dfs(i,t);
                count++;
            }
        }
    }
    printf("%d ",count);
    visited=vector<vector<bool>>(num,vector<bool>(num,false));
    count=0;
    for(int i=0;i<num;i++){
        for(int t=0;t<num;t++){
            if(squ[i][t]=='G'){
                squ[i][t]='R';
            }
        }
    }
    for(int i=0;i<num;i++){
        for(int t=0;t<num;t++){
            if(!visited[i][t]){
                dfs(i,t);
                count++;
            }
        }
    }
    printf("%d",count);
}