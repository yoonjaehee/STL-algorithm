//set 사용해보기(중복값 제거) + (저절로 정렬)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec,comp;
int main(){
    int n,s;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s);
        vec.push_back(s);
        comp.push_back(s);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=0;i<n;i++){
        printf("%d ",lower_bound(vec.begin(),vec.end(),comp[i])-vec.begin());
    }
    return 0;
}