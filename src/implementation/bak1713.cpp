#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<pair<int,int>,int>> vec;
int comp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b){
    if(a.first.first > b.first.first){  // 횟수 많으면 안바꿈
        return true;
    }
    else if(a.first.first == b.first.first){
        if(a.second > b.second){ // 왼쪽이 최신거일때 안바꿈 (클수록최신임)
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
int main(){
    int n,bing,temp;
    bool fid = false;
    scanf("%d",&n);
    scanf("%d",&bing);
    for(int i=0;i<bing;i++){
        fid = false;
        scanf("%d",&temp);
        for(auto it: vec){
            if(it.first.second == temp){
                it.first.first++;
                it.second = i;
                fid=true;
            }
        }
        if(!fid){ // 없었고 새로 추가해야될때
            if(vec.size()==n){
                vec.pop_back();
            }
            vec.push_back({{1,temp},i});
        }
        sort(vec.begin(),vec.end(),comp);
    }
    vector<int> res;
    for(int i=0;i<n;i++){
        res.push_back(vec[i].first.second);
    }
    sort(res.begin(),res.end());
    for(auto it: res){
        cout<<it<<" ";
    }
}