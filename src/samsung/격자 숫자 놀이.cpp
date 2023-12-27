#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
int r,c,k;
int arr[101][101]={0,};
int time = 0;
vector<pair<int,int>> vec;
map<int,int> ma;
bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.second > b.second){
        return false;
    }
    else if(a.second == b.second){
        if(a.first > b.first){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return true;
    }
}
int main(){
    scanf("%d %d %d",&r,&c,&k);
    for(int i=0;i<3;i++){
        for(int t=0;t<3;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    int cnt1 = 3; // 헹
    int cnt2 = 3; // 열
    while(1){
        if(time > 100){
            break;
        }
        if(arr[r-1][c-1] == k){
            break;
        }
        time++;
        if(cnt1 >= cnt2){
            for(int i=0;i<cnt1;i++){
                ma.clear();
                vec.clear();
                for(int t=0;t<cnt2;t++){
                    if(arr[i][t] != 0){
                        ma[arr[i][t]]++;
                    }
                }
                for(auto p : ma){
                    vec.push_back({p.first,p.second});
                }
                if(cnt2 < ma.size()*2){
                    cnt2 = ma.size()*2;
                    if(cnt2 > 100){
                        cnt2 = 100;
                    }
                }
                for(int t=0;t<101;t++){
                    arr[i][t] = 0;
                }
                sort(vec.begin(),vec.end(),cmp);
                for(int t=0;t<vec.size() && t<50;t++){
                    arr[i][t*2] = vec[t].first;
                    arr[i][t*2+1] = vec[t].second; 
                }
            }
            for(int i=0;i<cnt1;i++){
                for(int t=0;t<cnt2;t++){
                    printf("%d ",arr[i][t]);
                }
                printf("\n");
            }
        }
        else{
            for(int i=0;i<cnt2;i++){
                ma.clear();
                vec.clear();
                for(int t=0;t<cnt1;t++){
                    if(arr[t][i] != 0){
                        ma[arr[t][i]]++;
                    }
                }
                for(auto p : ma){
                    vec.push_back({p.first,p.second});
                }
                if(cnt1 < vec.size()*2){
                    cnt1 = vec.size()*2;
                    if(cnt1 > 100){
                        cnt1 = 100;
                    }
                }
                for(int t=0;t<101;t++){
                    arr[t][i] = 0;
                }
                sort(vec.begin(),vec.end(),cmp);
                for(int t=0;t<vec.size() && t<50;t++){
                    arr[t*2][i] = vec[t].first;
                    arr[t*2+1][i] = vec[t].second; 
                }
            }
            for(int i=0;i<cnt1;i++){
                for(int t=0;t<cnt2;t++){
                    printf("%d ",arr[i][t]);
                }
                printf("\n");
            }
        }
    }
    if(time > 100){
        printf("-1");
    }
    else{
        printf("%d",time);
    }
}