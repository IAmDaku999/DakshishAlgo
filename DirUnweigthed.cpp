#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map <int,vector<int>> DirectedGraph;
void Insert(int value,vector<int> v={}){
    DirectedGraph[value]=v;
}
class Box{
    public:
    int value=INT_MAX;
};
unordered_map <int,Box>SP;
void ShortestPath(int node,int SPParent=0){
    if (SP[node].value>SPParent)
    {
        SP[node].value=SPParent;
        for (auto i:DirectedGraph[node])
        {
            ShortestPath(i,SPParent+1);
        }
    }
}
void Print(){
    for (auto i:SP)
    {
        cout<<i.first<<":"<<i.second.value<<endl;
    }
    
} 
int main(int argc, char const *argv[])
{
    Insert(1,{2,6,3});
    Insert(2,{3,4});
    Insert(3,{6,4});
    Insert(4,{5});
    Insert(5,{6});
    ShortestPath(1);
    Print();
    return 0;
}