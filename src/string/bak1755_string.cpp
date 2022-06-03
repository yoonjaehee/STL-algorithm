#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,string>>vec;
vector<pair<string,int>>res;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vec.push_back({0,"zero"});
    vec.push_back({1,"one"});
    vec.push_back({2,"two"});
    vec.push_back({3,"three"});
    vec.push_back({4,"four"});
    vec.push_back({5,"five"});
    vec.push_back({6,"six"});
    vec.push_back({7,"seven"});
    vec.push_back({8,"eight"});
    vec.push_back({9,"nine"});
    for(int i=n;i<=m;i++){
        int temp=0;
        int temp2 = 0;
        if(i>=10){
            temp = i/10;
            temp2 = i%10;
            string ans = vec[temp].second + " " + vec[temp2].second;
            res.push_back({ans,i});
        }
        else{
            temp2 = i%10;
            string ans = vec[temp2].second;
            res.push_back({ans,i});
        }
    }
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        if(i%10 == 0 && i>0){
            printf("\n");
        }
        printf("%d ",res[i].second);
    }
}