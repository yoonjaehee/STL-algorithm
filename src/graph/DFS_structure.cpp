#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void DFS(int here){
    printf("DFS visits : %d", here);
    visited[here] = true;
    for(int i =0;i<adj[here].size();i++){
        int there = adj[here][i];
        if(!visited[there]){
            DFS(there);
        }
    }
 }
 void DFSAll(){
     visited = vector<bool>(adj.size(),false);
     for(int i=0;i<adj.size();i++){
         if(!visited[i]){
             DFS(i);
         }
     }
 }