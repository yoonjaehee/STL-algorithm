#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int>> pq = {{3,6},{4,3},{7,3},{9,10}};
    printf("%d\n", pq.size());
    printf("%d %d",pq[0][3][1],pq[0][3][1]);
}