#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n,m,temp,max,res;
    int lu,ld,rd,ru;
    int ans = 1;
    scanf("%d %d",&n,&m);
    char arr[n][m]={0,};
    cin.ignore();
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        for(int t=0;t<m;t++){
            arr[i][t] = s[t];
        }
    }
    (n>m)?(max=m):(max=n);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            for(int p=1;p<max;p++){
                if((t+p > m) || (i+p > n)){
                    break;;
                }
                lu = arr[i][t];
                ld = arr[i+p][t];
                ru = arr[i][t+p];
                rd = arr[i+p][t+p];
                if(lu == ld && ld == ru && ru == rd){
                    res = (p+1)*(p+1);
                    if(res >= ans){
                        ans = res;
                    }
                }
            }
        }
    }
    printf("%d",ans);
}