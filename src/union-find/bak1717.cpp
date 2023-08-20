#include <iostream>
#include <vector>
using namespace std;
int n,m,sign,a,b;
vector<int> vec(100);
int find(int tem){
    if(tem == vec[tem]){
        return tem;
    }
    else{
        return find(vec[tem]);
    }
}
bool conf(int p,int q){
    int tem1 = find(p);
    int tem2 = find(q);
    if(tem1 == tem2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    vec.resize(n+1);
    for(int i=0;i<=n;i++){
        vec[i] = i;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&sign,&a,&b);
        if(sign == 0){
            int temp = find(a);
            int temp2 = find(b);
            if(temp != temp2){
                vec[temp2] = temp;
            }
        }
        else{
            if(conf(a,b)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}