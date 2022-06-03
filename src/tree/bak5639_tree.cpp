#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
int index;
void preToPost(int start,int end){
    if(start >= end){
        return;
    }
    if(start == end-1){
        printf("%d\n",tree[start]);
        return;
    }
    index = start+1;
    while(index < end){
        if(tree[start] < tree[end]){
            break;
        }
        index++;
    }
    preToPost(start+1,index);
    preToPost(index,end);
    printf("%d\n",tree[start]);
}
int main(){
    int temp;
    while(scanf("%d",&temp) != EOF){
        tree.push_back(temp);
    }
    preToPost(0,tree.size());
}