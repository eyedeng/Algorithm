#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, int> m = {{1,10}};
    m.insert(make_pair(3,30));
    m.insert({2,20});
    m[4] = 44;
    unordered_map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    if(m.count(4))
        cout<<"have\n";

}