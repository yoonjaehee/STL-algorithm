<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> in,post;
// preorder 를 출력하는 함수 (재귀)
void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    // 더 이상 분할 할 수 없는 경우 return
    if (inStart > inEnd || postStart > postEnd)
        return;
    // postorder의 끝 값이 root값
    // Index 배열을 통해 inorder에서의 root index를 쉽게 구할 수 있다.
    int rootIndex = Index[postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;
    cout << inorder[rootIndex] << ' '; // root 값 출력

    // 재귀 함수 호출
    getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}
int main(){
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        in.push_back(temp);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        post.push_back(temp);
    }
    getpreorder(1,n,1,n);
}
||||||| merged common ancestors
=======
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
>>>>>>> b87cacedea254b3181d994c451ae2924d214b18d
