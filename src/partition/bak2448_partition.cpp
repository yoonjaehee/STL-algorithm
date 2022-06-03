#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> star;
void staring(int x,int y,int a){
    if(a==3){
        star[y][x]='*';
        star[y+1][x-1] ='*';
        star[y+1][x+1] ='*';
        for(int i=0;i<5;i++){
            star[y+2][x+i-2]='*';
        }
    }
    else{
        staring(x,y,a/2);
        staring(x-a/2,y+a/2,a/2);
        staring(x+a/2,y+a/2,a/2);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    star = vector<vector<char>>(n,vector<char>(2*n-1,' ')); 
    staring(n-1,0,n);
    for(int i=0;i<n;i++){
        for(int t=0;t<2*n-1;t++){
            printf("%c",star[i][t]);
        }
        printf("\n");
    }
}