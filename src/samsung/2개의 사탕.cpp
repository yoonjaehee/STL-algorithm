#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[10][10];
bool visited[10][10];
priority_queue<int> pq;
queue<pair<pair<int,int>,pair<int,int>>> q; 
int endy,endx;
int n,m,ny,nx;
int redy, redx, bly,blx;
int py[4] = {1,0,-1,0};
int px[4] = {0,1,0,-1};
void mov(pair<int,int> a, int direct,bool bl){
    
}
int main(){
    scanf("%d %d",&n,&m);
    string str;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,str);
        for(int t=0;t<m;t++){
            if(str[t] == '#'){
                arr[i][t] = 0;
            }
            else if(str[t] == '.'){
                arr[i][t] = 1;
            }
            else if(str[t] == 'R'){
                arr[i][t] = 1;
                redy = i;
                redx = t;
            }
            else if(str[t] == 'B'){
                arr[i][t] = 1;
                bly = i;
                blx = t;
            }
            else{
                arr[i][t] = 1;
                endy = i;
                endx = t;
            }
        }
    }
    q.push({{redy,redx},{bly,blx}}});
    if(pq.empty()){
        printf("-1");
    }
    else{
        printf("%d",pq.top());
    }
}