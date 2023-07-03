#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    vector<int> num;
    int sum[100001];
    scanf("%d %d",&n,&m);
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        num.push_back(temp);
        if(i>0){
            sum[i] = sum[i-1] + temp;
        }
        else if(i==0){
            sum[i] = temp;
        }
    }
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        if(a==1){
            printf("%d\n",sum[b-1]);
        }
        else{
            printf("%d\n",sum[b-1] - sum[a-2]);
        }
    }
}