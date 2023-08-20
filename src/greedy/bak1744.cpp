#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    int one = 0;
    int zero = 0;
    scanf("%d",&n);
    priority_queue<int> pl;
    priority_queue<int,vector<int>,greater<int>> mi;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp < 0){
            mi.push(temp);
        }
        else if(temp > 0){
            pl.push(temp);
        }
        else if(temp == 1){
            one++;
        }
        else if(temp == 0){
            zero++;
        }
    }
    int sum = 0;
    int data1,data2;
    while(pl.size()>1){
        data1 = pl.top();
        pl.pop();
        data2 = pl.top();
        pl.pop();
        sum+=(data1*data2);
    }
    if(!pl.empty()){
        sum+=pl.top();
        pl.pop();
    }
    while(mi.size()>1){
        data1 = pl.top();
        pl.pop();
        data2 = pl.top();
        pl.pop();
        sum+=(data1*data2);
    }
    if(!mi.empty()){
        if(zero == 0){
            sum+=mi.top();
            mi.pop();
        }
    }
    sum+=one;
    printf("%d",sum);
}