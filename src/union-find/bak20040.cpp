#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> vec(100001);
int find(int a){
    if(a == vec[a]){
        return a;
    }
    else{
        return vec[a] = find(vec[a]);
    }
}
void unin(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(a>=b){
            vec[a] = b; 
        }
        else{
            vec[b] = a;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    vec.reize(n+1);*
    for(int i=0;i<m;i++){
        scanf("%d %d",&temp1,&temp2);

    }
}