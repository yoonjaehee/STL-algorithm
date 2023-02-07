#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int n,l;
int maxi=0;
int mini= INT_MAX;
vector<pair<int,int>> vec;
int main(){
    int temp1,temp2,res,count;
    int total = 0;
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++){
        scanf("%d %d",&temp1,&temp2);
        if(temp1 < mini){
            mini = temp1;
        }
        if(temp2 > maxi){
            maxi = temp2;
        }
        vec.push_back({temp1,temp2});
    }
    sort(vec.begin(),vec.end());
    /* 생각해봤는데 그냥 완전탐색하려고 했는데 오래걸릴듯.. 그리고 비효율적
    bool arr[maxi] = {false,};
    for(int i=0;i<vec.size();i++){
        for(int t=vec[i].first;t<=vec[i].second;t++){
            arr[t] = true;
        }
    }
    */
   /*그래서 시작 + L단위*? >마지막 웅덩이 만족하는 ? 구하고 초과해서 true로 바꾸고
   다음에 시작하는게 이안에 있으면(sort해서 확인) 다음시점부터 다시 탐색 */
    for(int i=0;i<n;i++){
        count=vec[i].second-vec[i].first; 
        if(count%l != 0){ // 나누어 떨어지지 않을때, 
            if(vec[i].second+(l-(vec[i].second - (vec[i].first + ((count/l)*l)))) >= vec[i+1].first && (i != n-1)){
                vec[i+1].first = vec[i].second+(l-(vec[i].second - (vec[i].first + ((count/l)*l)))) + 1;
            }
            res=count/l + 1;
        }
        else{
            res=count/l;
        }
        total+=res;
    }
    printf("%d",total);
}