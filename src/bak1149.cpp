#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int sum[n][3]={0,};
    int temp1,temp2,temp3;
    for(int i=0;i<n;i++){
        scanf("%d",&temp1);
        scanf("%d",&temp2);
        scanf("%d",&temp3);
        sum[i+1][0]=min(sum[i][1],sum[i][2]) + temp1;
        sum[i+1][1]=min(sum[i][0],sum[i][2]) + temp2;
        sum[i+1][2]=min(sum[i][0],sum[i][1]) + temp3;
    }
    printf("%d",min(sum[n][0],min(sum[n][1],sum[n][2])));

}