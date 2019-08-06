#include <map>
using namespace std;


int main()
{
    map<int,char> bst;
    bst.insert(make_pair(14,'n'));
    bst[15] = 's';
    bst[16] = 'e';
    bst[4] = 'i';
    bst[92] = 't';
    bst[37] = 'r';
    for(auto it = bst.begin(); it!=bst.end(); it++)
    {
        cout<<it->second<<" ";
    }
    bst.erase(37);
    auto itl = bst.lower_bound(15);   // >= key
    auto itu = bst.upper_bound(15);   // > key
    cout<<itl->first<<" "<<itu->first<<endl;

    return 0;
}