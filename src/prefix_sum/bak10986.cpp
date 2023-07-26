#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,temp,tm;
    int count = 0;
    scanf("%d %d",&n,&m);
    vector<long> vec(m,0);//나머지 
    vector<long> sum(n,0);
    temp = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        sum[i] = sum[i-1] + temp;
    }
    for(int i=0;i<n;i++){
        int now = sum[i] % m;
        if(now == 0){
            count++;
        }
        vec[now]++;
    }
    printf("%d",count);
}