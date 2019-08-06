#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int id,sum;
    double num;
    bool operator<(const Node& n)const{
        if(id == n.id)
            return sum < n.sum;
        return id < n.id;
    }
};
int main()
{
    //Node no = {1,1,2.0};
    vector<Node> v;
    v.push_back(Node{1, 5, 10});  //
    v.push_back(Node{4, 3, 10});
    v.push_back(Node{3, 15, 10});
    v.push_back(Node{4, 50, 10});
    v.push_back(Node{3, 5, 10});
    sort(v.begin(), v.end());
    for(auto i : v)
    {
        cout<<i.id<<" "<<i.sum<<endl;
    }
    return 0;
}

