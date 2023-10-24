#include <iostream>
#include <math.h>
using namespace std;
int num;
bool isprime(int start){
    for(int t=2;t<=sqrt(start);t++){
        if(start%t == 0){
            return false;
        }
    }
    return true;
}
void dfs(int n,int cnt){
    if(cnt == num){
        if(isprime(n)){
            cout<<n<<endl;
        }
        return;
    }
    for(int i=1;i<=9;i++){
        if(i%2 == 0){
            continue;
        }
        if(isprime(n*10+i)){
            dfs(n*10+i,cnt+1);
        }
    }

}
int main(){
    scanf("%d",&num);
    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
}
