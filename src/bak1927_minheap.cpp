#include <iostream>
#include <vector>
using namespace std;
vector<int> heap;
vector<int> print_heap;
void minheap(int x){
    if(x==0){
        if(heap.size()==0){
            print_heap.push_back(0);
        }
        else{
            print_heap.push_back(heap.front());
            heap.erase(heap.begin());
            int count=heap.size();
        }
        
    }
    else{
        heap.push_back(x);
        int count=heap.size();
        while(count>=2){
            if(heap[count-1]<heap[(count-1)/2]){
                int temp = heap[count-1];
                heap[count-1] = heap[(count-1)/2];
                heap[(count-1)/2] = temp;
                count/=2;
            }
            else{
                break;
            }
        }
    }

}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        minheap(x);
    }
    for(int t=0;t<print_heap.size();t++){
        printf("%d\n", print_heap[t]);
    }
}