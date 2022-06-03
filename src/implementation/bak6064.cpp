#include <iostream>
#include <vector>
using namespace std;
int main(){
    int num,m,n,x,y;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        bool exist = false;
        scanf("%d %d %d %d",&m,&n,&x,&y);
        x=x-1;
        y=y-1;
        for(int t=0;t<n;t++){
            int point = m*t+x;
            if(point%n==y){
                exist=true;
                printf("%d\n",point+1);
                break;
            }
        }
        if(exist == false){
            printf("-1\n");
        }
    }
    return 0;
}