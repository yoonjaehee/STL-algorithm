// 문자열로부터 해시 값을 생성하는 용도로 std::hash<std::string>(std::string) 함수 객체 제공.
// chaining hash table 을 templete 형태로 바꾸면 모든 데이터 타입으로 사용할 수 있는데
// STL에서는 std::unordered_set<key>, std::unordered_map<key,value>로 사용 가능. - elem.first, elem.second
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void print(const unordered_set<int>& container){
    for(auto& elem: container){
        printf("%d ", elem);
    }
    printf("\n");
}
void print(const unordered_map<int, int>& container){
    for(auto& elem: container){
        printf("%d: %d", elem.first, elem.second);
    }
    printf("\n");
}
void find(const unordered_set<int>& container, const int element){
    if(container.find(element)==container.end()){
        printf("없다");
    }
    else{
        printf("있다");
    }
}
void find(const unordered_map<int, int>& container, const int element){
    auto it = container.find(element);
    if(container.find(element) == container.end()){
        printf("없다");
    }
    else{
        printf("%d에 %d있다", it-> first, it->second); // 그냥 container.first 써버리면 어디위치인지몰라서안댐.
                                                      // 그래서 it로 찾아버리고 위치에 해당하는거 출력 
    }
}
