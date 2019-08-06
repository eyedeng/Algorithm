#include <iostream>
#include <list>
using namespace std;

int main()
{
    int len;
    int ele;
    list<int> lis;
    cin>> len;
    while(len--)
    {
        cin>>ele;
        lis.push_back(ele);
    }
    int delele;
    cin>> delele;
    lis.remove(delele);
    cout<<lis.size()<<"¸ö:  ";
    for(list<int>::iterator it = lis.begin(); it!=lis.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
