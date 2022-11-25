#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
using namespace std;
int num;
int arr[101][101];
bool checked[22];
int mi = INT_MAX;
void DFS(int count,int next){
    int team1,team2,res;
    if(count == num/2){
        team1 = 0;
        team2 = 0;
        for(int i=1;i<=num;i++){
            for(int t=1;t<=num;t++){
                if(checked[i] == true && checked[t] == true){
                    team1+=arr[i][t];
                }
                if(checked[i] == false && checked[t] == false){
                    team2+=arr[i][t];
                }
            }
        }
        res = abs(team1-team2);
        if(mi> res){
            mi = res;
        }
        return;
    }
    for(int i=next;i<num;i++){
        checked[i]= true;
        DFS(count+1,next+1);
        checked[i]=false;
    }

}
int main(){
    int temp;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        for(int t=1;t<=num;t++){
            scanf("%d",&temp);
            arr[i][t]=temp;
        }
    }
    DFS(0,1);
    printf("%d",mi);
}