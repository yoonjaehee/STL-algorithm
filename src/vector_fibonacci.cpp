#include <iostream>
#include <vector>
using namespace std;
int fibonacci(int n,int* count_zero,int* count_one) {
    if (n == 0) {
        *count_zero+=1;
    } 
    else if (n == 1) {
        *count_one+=1;
    } 
    else {
        fibonacci(n-1,count_zero,count_one) + fibonacci(n-2,count_zero,count_one);
    }
    return 0;
}
int main(){
    int T;
    int *pt1, *pt2;
    scanf("%d", &T);
    vector<int> vec;
    for(int i=0;i<T;i++){
        int fibNum;
        int po_num1=0;
        int po_num2=0;
        scanf("%d", &fibNum);
        fibonacci(fibNum,&po_num1,&po_num2);
        pt1=&po_num1;
        pt2=&po_num2;
        vec.push_back(*pt1);
        vec.push_back(*pt2);
    }
    for(int i=0;i<T;i++){
        printf("%d %d\n", vec[i*2], vec[i*2+1]);
    }
    
}