#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,temp;
int main(){
    vector<pair<int,int>> vec;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        int sc1,sc2;
        vec.clear();
        for(int t=0;t<temp;t++){
            scanf("%d %d",&sc1,&sc2);
            vec.push_back({sc1,sc2});
        }
        sort(vec.begin(),vec.end());
        int idx = 0;
        int res = 1;
        for(int t=1;t<temp;t++){
            if(vec[idx].second > vec[t].second){
                res++;
                idx = t;
            }
        }
        printf("%d",res);
    }
}