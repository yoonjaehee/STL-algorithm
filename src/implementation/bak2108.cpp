#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
using namespace std;
int main(){
    int temp;
    float n;
    cin>>n;
    float sum = 0;
    int mx = 0;
    int mi = INT_MAX;
    vector<int> vec;
    vector<int> res(8000,0);
    int count = 0;
    for(int i=0;i<n;i++){
        cin>>temp;
        sum+=temp;
        vec.push_back(temp);
        res[4000+temp]++;
        if(count < res[4000+temp]){
            count = res[4000+temp];
        }
    }
    sort(vec.begin(),vec.end());
    int res4 = vec[n-1] - vec[0];
    int res1 = round(sum/n);
    int res2 = vec[(n/2)];
    int flag = 0;
    int res3 = 0;
    for(int i=0;i<=8000;i++){
        if(count==res[i]){
            flag++;
            res3 = i-4000;
        }
        if(flag == 2){
            res3 = i-4000;
            break;
        }
    }
    printf("%d\n%d\n%d\n%d\n",res1,res2,res3,res4);
}