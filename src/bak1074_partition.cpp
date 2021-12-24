#include <iostream>

using namespace std;
int n,r,c;
int ans=0;
void graph(int x,int y,int s){
    if(x==r && y==c){
        printf("%d", ans);
        return;
    }
    if(x+s>r && r>=x && y+s>c && c>=y){
        graph(x,y,s/2);
        graph(x,s/2+y,s/2);
        graph(s/2+x,y,s/2);
        graph(s/2+x,s/2+y,s/2);
    }
    else{
        ans += s*s;
    }
}
int main()
{
    scanf("%d %d %d", &n,&r,&c);
    graph(0,0,(1<<n));
    return 0;
}
