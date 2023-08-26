#include <iostream>
#include <vector>
using namespace std;
int n,m,real,psize;
vector<int> vec(51);
vector<int> tp;
vector<vector<int>> party;
int find(int a){
    if(a == vec[a]){
        return a;
    }
    else{
        return vec[a] = find(vec[a]);
    }
}
void unio(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        vec[b] = a;
    }
}
int main(){
    int ans = 0;
    scanf("%d %d",&n,&m);
    scanf("%d",&real);
    vec.resize(n+1);
    tp.resize(real);
    for(int i=1;i<=n;i++){
        vec[i] = i;
    }
    for(int i=0;i<real;i++){
        scanf("%d",&tp[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&psize);
        for(int t=0;t<psize;t++){
            int temp;
            scanf("%d",&temp);
            party[i].push_back(temp);
        }
    }
    for(int i=0;i<m;i++){
        int start = party[i][0];
        for(int t=1;t<party[i].size();t++){
            unio(start,party[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        bool pos = true;
        int cur = party[i][0];
        for(int t=0;t<real;t++){
            if(find(cur) == find(tp[t])){
                pos = false;
                break;
            }
        }
        if(pos){
            ans++;
        }
    }
    printf("%d",ans);
}