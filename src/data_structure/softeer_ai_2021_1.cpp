#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main(){
    int cm,bg,temp;
    int max = 0;
    vector<int> vec;
    scanf("%d %d",&cm,&bg);
    for(int i=0;i<cm;i++){
        scanf("%d",&temp);
        if(max < temp){
            max = temp;
        }
        vec.push_back(temp);
    }
    temp = 0;
    int arr[max] = {0,};
    for(int i=0;i<vec.size();i++){
        arr[vec[i]]++;
    }
    int total = 0;
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        temp = total;
        total+=vec[i]*vec[i]*arr[vec[i]];
        if(total > bg){
            printf("total : %d", total);
            printf("%d",vec[i]);
            return 0;
        }
    }
    while(1){
        if(total > bg){
            printf("%d",max);
            return 0;
        }
        total+=(max*max*cm);
        max+=1;
    }
}