#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> post,in;
void pre(){
    
}
int main(){
    scanf("%d",&n);
    post = vector<int>(n,0);
    in = vector<int>(n,0);
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    pre();
}