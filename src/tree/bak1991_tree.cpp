#include <iostream>
#include <vector>
using namespace std;
int n;
pair<int,int> node[26];
void preorder(char a){
    if(a == '.'){
        return;
    }
    printf("%c",a);
    preorder(node[a-'A'].first);
    preorder(node[a-'A'].second);
}
void inorder(char a){
    if(a == '.'){
        return;
    }
    inorder(node[a-'A'].first);
    printf("%c",a);
    inorder(node[a-'A'].second);
}
void postorder(char a){
    if(a == '.'){
        return;
    }
    postorder(node[a-'A'].first);
    postorder(node[a-'A'].second);
    printf("%c",a);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char temp1,temp2,ma;
        cin>>ma>>temp1>>temp2;
        node[ma-'A'] = {temp1,temp2};
    }
    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
}