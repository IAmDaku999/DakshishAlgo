#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map <int,vector<pair<int,int>>> UnDirGraph;
void Insert(int value,vector<pair<int,int>> v={}){
    UnDirGraph[value]=v;
    for (int i = 0; i < v.size(); i++)
    {
        UnDirGraph[v.at(i).first].push_back(pair(value,v.at(i).second));
    }
}
class Box{
    public:
    int value =INT_MAX;
};
unordered_map <int,Box>SP;
void ShortestPath(int node,int SPParent=0){
    if (SP[node].value>SPParent)
    {
        SP[node].value=SPParent;
        for (auto i:UnDirGraph[node])
        {
            ShortestPath(i.first,SPParent+i.second);
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
    Insert(1,{pair(2,7),pair(6,14),pair(3,9)});
    Insert(2,{pair(3,10),pair(4,15)});
    Insert(3,{pair(6,2),pair(4,11)});
    Insert(4,{pair(5,6)});
    Insert(5,{pair(6,9)});
    ShortestPath(1);
    Print();
    return 0;
}

