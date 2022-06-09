#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    for(int i=0;i<t;t++){
        map<string,int> ma;
        vector<pair<pair<pair<string,int>,int>,int>>car;
        vector<pair<pair<pair<int,string>,char>,int>>rent;
        int n,m;
        scanf("%d",&t);
        scanf("%d %d",&n,&m);
        for(int v=0;v<n;v++){
            string N;
            int p,q,k; // 원가, 초기 대여 비용, 주행거리 1km 당 비용
            scanf("%s %d %d %d",N,&p,&q,&k);
            car.push_back({{{N,p},q},k});
        }
        for(int v=0;v<m;v++){
            int ti;
            char e;
            string S,E;
            scanf("%d %s %c",&ti,S,&e); // 사건 발생 시각,첩보원 이름, 사건의 종류 
            if(e=='p'){
                string C;
                scanf("%s",C);
                
            }
            else if(e=='r'){
                int d;
                scanf("%d",&d);
            }
            else if(e=='a'){
                int s;
                scanf("%d",&s);
            }
        }
    }
    for(int i=0;i<ma.size();i++){
        if(ma[i].second = -1){
            printf("%s INCONSISTENT");
        }
        else{
            printf("%s %d",ma[i].first,ma[i].second);
        }
    }
}