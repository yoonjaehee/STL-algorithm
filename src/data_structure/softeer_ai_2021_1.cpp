#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
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
    int tm = 0;
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        temp = vec[i+1]-vec[i];
        total+=temp*temp*arr[vec[i]];
        if(total > bg){
            int answer = sqrt(bg/arr[vec[i]]);
            printf("%d",answer+vec[i]);
            return 0;
        }
        arr[vec[i]+1] += arr[vec[i]];
    }
}