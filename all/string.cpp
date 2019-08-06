#include <iostream>
#include <iterator>
#include <algorithm>
//#include <string>
using namespace std;

template <class T>
T mi3(T a, T b,T c){
    return min(a,min(b,c));
}
int main()
{
    /*string s("a string .");

    s += "not a char\n";
    cout << s.at(0) << endl;
    cout << s << endl;
    int ar[10] = {3,4,5,3,2,2,6,34,3,90};
    for(int x:ar)
        cout << x << " ";
    cout <<endl;
    for(int *p = begin(ar); p != end(ar); p++)
        cout << *p << " ";
    */
    string s1="good",s2("morning");
    s1 += (" "+s2+"!");
    cout<< s1<<endl<<s1[0]<<endl;
    cout<< s1.substr(1,3)<<endl;
    string s,pre_add;
    while(cin>>pre_add)
    {
        s = pre_add + s;
        cout<<s<<endl;
    }

    return 0;
}
