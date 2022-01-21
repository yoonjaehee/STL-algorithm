#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
char graph[1001][1001]={0,};
int main(){
    string s;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",&graph[i][0]);
    }
    printf("%c",graph[1][1]);
}