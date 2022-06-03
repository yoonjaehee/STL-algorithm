#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp_max[3]={0,};
int dp_min[3]={0,};
char arr[100001][3]={0,};
void DP(){
    for(int i=0;i<3;i++){
        dp_max[i] = arr[0][i];
        dp_min[i] = arr[0][i];
    }
    for(int i=1;i<=n;i++){
        int temp1 = dp_max[0];
        int temp2 = dp_max[1];
        int temp3 = dp_max[2];
        int temp4 = dp_min[0];
        int temp5 = dp_min[1];
        int temp6 = dp_min[2];
        dp_max[0]=max(temp1,temp2)+arr[i][0];
        dp_max[1]=max(max(temp1,temp2),temp3)+arr[i][1];
        dp_max[2]=max(temp2,temp3)+arr[i][2];
        dp_min[0]=min(temp4,temp5)+arr[i][0];
        dp_min[1]=min(min(temp4,temp5),temp6)+arr[i][1];
        dp_min[2]=min(temp5,temp6)+arr[i][2];
    }
}
int main(){
    scanf("%d",&n);
    int res_max,res_min;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    DP();
    res_max = max(max(dp_max[0],dp_max[1]),dp_max[2]);
    res_min = min(min(dp_min[0],dp_min[1]),dp_min[2]);
    printf("%d %d",res_max,res_min);
}