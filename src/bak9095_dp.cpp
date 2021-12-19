#include <iostream>
#include <vector>
using namespace std;
int cou=0;
vector<int> ans;
vector<int> cache(12,-1);
int count(int a){
    if(a==1){
        return 1;
    }
    if(a==2){
        return 2;
    }
    if(a==3){
        return 4;
    }
    if(cache[a]!=-1){
        return cache[a];
    }
    return cache[a] = count(a-1) + count(a-2) + count(a-3);
}   
int main(){
    int num,cau;
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        scanf("%d", &cau);
        ans.push_back(count(cau));
    }
    for(int i=0;i<num;i++){
        printf("%d\n",ans[i]);
    }
}