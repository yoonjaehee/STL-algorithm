#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,m;
vector<int>vec(1001);
int arr[201][201];
int find(int a){
    if(a == vec[a]){
        return a;
    }
    else{
        return vec[a] = find(vec[a]);
    }
}
int unio(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        vec[b] = a;
    }
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    vec.resize(m+1);
    for(int i=0;i<n+1;i++){
        memset(arr[i],0,sizeof(int)*(n+1));
    }
    for(int i=0;i<=m;i++){
        vec[i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int t=1;t<=n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    int route[1001];
    for(int i=1;i<=m;i++){
        scanf("%d",&route[i]);
    }
    for(int i=1;i<=n;i++){
        for(int t=1;t<=n;t++){
            if(arr[i][t] == 1){
                unio(i,t);
            }
        }
    }
    int idx = find(route[1]);
    bool connect = true;
    for(int i=2;i<=m;i++){
        if(idx != find(route[i])){
            printf("NO");
            connect = false;
            break;
        }
    }
    if(connect){
        printf("YES");
    }
}