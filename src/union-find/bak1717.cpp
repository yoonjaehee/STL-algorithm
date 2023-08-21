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
        return vec[tem] = find(vec[tem]); // find 시간 복잡도 최대한 줄이기. 연산을 할때 거치는 노드들이 대표 노드와 바로 연결되는 형태로 변경...
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