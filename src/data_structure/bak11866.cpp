#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n,m,temp2;
    queue<int> q;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    printf("<");
    for(int i=0;i<n-1;i++){
        for(int t=0;t<m-1;t++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        temp2 = q.front();
        q.pop();
        printf("%d, ",temp2);
    }
    temp2 = q.front();
    q.pop();
    printf("%d>",temp2);
    
}