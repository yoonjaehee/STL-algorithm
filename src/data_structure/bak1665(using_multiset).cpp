#include <iostream>
#include <set>
using namespace std;
int main(){
    int temp;
    int n;
    int count = 0;
    multiset<int> vec;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.insert(temp);
        if(i>=1){
            auto it = vec.begin();
            for(int p=0;p<i/2;p++){
                it++;
            }
            printf("%d",*it);
        }
    }
}