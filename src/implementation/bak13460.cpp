#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,m;
pair<int,int> goal;
void dfs(int count,vector<vector<char>> ch,int rsy,int rsx,int bsy,int bsx){
    vector<vector<char>>tem = ch;
    if(count > 10){
        printf("-1");
        return;
    }
    if(bsy == goal.first && bsx == goal.second){
        return;
    }
    if(rsy == goal.first && rsx == goal.second){
        printf("%d",count);
        return;
    }
    for(int i=rsx-1;i>0;i--){ // 왼쪽으로 몰기
        if(tem[rsy][i] == '#'){
            if(bsy == rsy){
                tem[rsy][rsx]='.';
                tem[bsy][bsx]='.';
                if(bsx > rsx){
                    dfs(count+1,tem,i+1,rsx,i+2,bsx);
                }
                else{
                    dfs(count+1,tem,i+2,rsx,i+1,bsx);
                }
            }
            else{
                for(int t=bsx-1;t>0;t--){
                    if(tem[bsy][t] == '#'){
                        tem[rsy][rsx] = '.';
                        tem[bsy][bsx] = '.';
                        dfs(count+1,tem,i+1,rsx,t+1,bsx);
                    }
                }
            }
        }
    }
    for(int i=rsx+1;i<n;i++){ // 오른쪽으로 몰기
        if(tem[rsy][i] == '#'){
            if(bsy == rsy){
                tem[rsy][rsx]='.';
                tem[bsy][bsx]='.';
                if(bsx > rsx){
                    dfs(count+1,tem,i+1,rsx,i+2,bsx);
                }
                else{
                    dfs(count+1,tem,i+2,rsx,i+1,bsx);
                }
            }
            else{
                for(int t=bsx+1;t<m;t++){
                    if(tem[bsy][t] == '#'){
                        tem[rsy][rsx] = '.';
                        tem[bsy][bsx] = '.';
                        dfs(count+1,tem,i-1,rsx,t-1,bsx);
                    }
                }
            }
        }
    }
    for(int i=rsy-1;i>0;i--){ // 위쪽으로 몰기
        if(tem[i][rsx] == '#'){
            if(bsx == rsx){
                tem[rsy][rsx]='.';
                tem[bsy][bsx]='.';
                if(bsy > rsy){
                    dfs(count+1,tem,rsy,i+1,bsy,i+2);
                }
                else{
                    dfs(count+1,tem,rsy,i+2,bsy,i+1);
                }
            }
            else{
                for(int t=bsy-1;t>0;t--){
                    if(tem[t][bsx] == '#'){
                        tem[rsy][rsx] = '.';
                        tem[bsy][bsx] = '.';
                        dfs(count+1,tem,rsy,i+1,bsy,t+1);
                    }
                }
            }
        }
    }
    for(int i=rsy+1;i<m;i++){ // 아래쪽으로 몰기
        if(tem[i][rsx] == '#'){
            if(bsx == rsx){
                tem[rsy][rsx]='.';
                tem[bsy][bsx]='.';
                if(bsy > rsy){
                    dfs(count+1,tem,rsy,i-1,bsy,i-2);
                }
                else{
                    dfs(count+1,tem,rsy,i-2,bsy,i-1);
                }
            }
            else{
                for(int t=bsy+1;t<m;t++){
                    if(tem[t][bsx] == '#'){
                        tem[rsy][rsx] = '.';
                        tem[bsy][bsx] = '.';
                        dfs(count+1,tem,rsy,i-1,bsy,t-1);
                    }
                }
            }
        }
    }
    printf("dfs execute");
}
int main(){
    char temp,res;
    scanf("%d %d",&n,&m);
    vector<vector<char>> vec(n,vector<char>(0,m));
    int arr[n+1][m+1]={0,};
    pair<int,int> rstart,bstart;
    vector<string> sem;
    string s;
    for(int i=0;i<n;i++){
        cin.clear();
        cin.sync();
        getline(cin,s);
        sem.push_back(s);
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            temp=sem[i][t];
            vec[i].push_back(temp);
            if(temp == 'R'){
                rstart.first = i;
                rstart.second = t;
            }
            if(temp == 'B'){
                bstart.first = i;
                bstart.second = t;
            }
            if(temp == 'O'){
                goal.first = i;
                goal.second = t;
            }
        }
    }
    dfs(0,vec,rstart.first,rstart.second,bstart.first,bstart.second);
}